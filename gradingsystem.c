#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Structure to store student information
struct Student {
    int ID, Mark_1, Mark_2, Mark_3, Mark_4, Mark_5, total;
    float average;
    char Fname[50], Lname[50], grade[3];
};

// Pointer to dynamically allocated array of students
struct Student* Students = NULL; 
// Number of students currently in the system
int count = 0;  
// Current capacity of the dynamic array
int capacity = 10;  

// Function prototypes
void clear_input_buffer();
bool read_integer(const char* prompt, int* value, int min, int max);
bool read_string(const char* prompt, char* str, int max_len);
void add_student();
void display_all_students();
void search_student();
void find_class_topper();
void display_grade_distribution();
void update_marks();
void display_class_performance();
void calculate_grade(struct Student* student);
void free_memory();
void sort_students();
void save_data(const char* filename);
void load_data(const char* filename);


int main() {
    int choice;

    puts("*** Student Grading System ***");

    // Dynamically allocate initial memory for the students array
    struct Student* new_students = realloc(Students, capacity * sizeof(struct Student));
    if (new_students == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }


    load_data( "student_data.txt" );

    while (true) {
        printf("\n");
        puts("1. Add a New Student");
        puts("2. Display All Students");
        puts("3. Search Student by ID/Name");
        puts("4. Class Topper");
        puts("5. Grade Distribution");
        puts("6. Update Marks");
        puts("7. Class Performance Summary");
        puts("8. Sort Students");
        puts("9. Exit");

        if (!read_integer("\nEnter your choice: !_ ", &choice, 1, 9)) {
            continue;
        }

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                find_class_topper();
                break;
            case 5:
                display_grade_distribution();
                break;
            case 6:
                update_marks();
                break;
            case 7:
                display_class_performance();
                break;
            case 8:
                sort_students();
                break;
            case 9:
                puts("Exiting the program. Goodbye!");
                save_data( "student_data.txt" );
                free_memory(); // Free dynamically allocated memory
                return 0;
            default:
                printf("!!Invalid Choice!!\n\n");
                break;
        }
    }
    // Save data before exiting
    return 0;
}

// Function implementations

// Clears the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clears buffer
}

// Reads an integer from the user within a specified range
bool read_integer(const char* prompt, int* value, int min, int max) {
    char buffer[100];
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            // Validate if the input is an integer
            if (sscanf(buffer, "%d", value) == 1) {
                // Check range
                if (*value >= min && *value <= max) {
                    return true;
                } else {
                    printf("Error: Please enter a number between %d and %d.\n", min, max);
                }
            } else {
                printf("Error: Please enter a valid integer.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }
}

// Reads a string from the user
bool read_string(const char* prompt, char* str, int max_len) {
    printf("%s", prompt);
    if (fgets(str, max_len, stdin)) {
        str[strcspn(str, "\n")] = 0; // Remove newline character
        if (strlen(str) > 0 && strspn(str, " \t") != strlen(str)) {
            return true;
        }
    }
    printf("Invalid input! Please enter a valid non-empty string.\n");
    return false;
}

// Adds a new student to the system
void add_student() {
    // Resize the array if capacity is full
    if (count == capacity) {
        capacity *= 2;
        struct Student* new_students = (struct Student*)realloc(Students, capacity * sizeof(struct Student));
        
        if (new_students == NULL) {
            printf("Memory reallocation failed! Cannot add more students.\n");
            return;
        }
        Students = new_students;
    }

    printf("Adding a new student...\n");

    // Loop until a unique ID is entered
    while (true) {
        read_integer("Enter Student ID (1-9999): !_ ", &Students[count].ID, 1, 9999);

        bool id_unique = true;
        for (int i = 0; i < count; i++) {
            if (Students[i].ID == Students[count].ID) {
                printf("Error: Student ID %d already exists. Please try again.\n", Students[count].ID);
                id_unique = false;
                break;
            }
        }

        if (id_unique) {
            break;
        }
    }

    // Get student details
    if (!read_string("Enter First Name: !_ ", Students[count].Fname, sizeof(Students[count].Fname))) {
        return;
    }

    if (!read_string("Enter Last Name: !_ ", Students[count].Lname, sizeof(Students[count].Lname))) {
        return;
    }

    Students[count].total = 0;
    for (int i = 1; i <= 5; i++) {
        char prompt[50];
        snprintf(prompt, sizeof(prompt), "Enter Mark for Subject %d (0-100): !_ ", i);
        int mark;
        if (!read_integer(prompt, &mark, 0, 100)) {
            return;
        }

        Students[count].total += mark;
        switch (i) {
            case 1: Students[count].Mark_1 = mark; break;
            case 2: Students[count].Mark_2 = mark; break;
            case 3: Students[count].Mark_3 = mark; break;
            case 4: Students[count].Mark_4 = mark; break;
            case 5: Students[count].Mark_5 = mark; break;
        }
    }

    Students[count].average = (float)Students[count].total / 5;
    calculate_grade(&Students[count]);
    count++;
    printf("Student added successfully!\n");
}

// Displays information for all students
void display_all_students() {
    printf("Displaying all students:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s %s, Total: %d, Average: %.2f, Grade: %s\n",
               Students[i].ID, Students[i].Fname, Students[i].Lname,
               Students[i].total, Students[i].average, Students[i].grade);
    }
}

// Searches for a student by ID or name
void search_student() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    int search_option;
    do {
        puts("\nSearch Options:");
        puts("1. Search by Student ID");
        puts("2. Search by Student Name");
        if (!read_integer("Enter your choice: !_ ", &search_option, 1, 2)) {
            continue;
        }
    } while (search_option < 1 || search_option > 2);

    if (search_option == 1) {
        int search;
        if (!read_integer("Enter Student ID: !_ ", &search, 1, 9999)) {
            return;
        }

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (Students[i].ID == search) {
                printf("ID: %d, Name: %s %s, Total: %d, Average: %.1f, Grade: %s\n",
                       Students[i].ID, Students[i].Fname, Students[i].Lname, Students[i].total, Students[i].average, Students[i].grade);
                found = true;
                break;
            }
        }

        if (!found) {
            puts("Student ID not found!");
        }
    } else {
        char search_name[50];
        if (!read_string("Enter Student First Name or Last Name: !_ ", search_name, sizeof(search_name))) {
            return;
        }

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (strcmp(Students[i].Fname, search_name) == 0 || strcmp(Students[i].Lname, search_name) == 0) {
                printf("ID: %d, Name: %s %s, Total: %d, Average: %.1f, Grade: %s\n",
                       Students[i].ID, Students[i].Fname, Students[i].Lname, Students[i].total, Students[i].average, Students[i].grade);
                found = true;
            }
        }

        if (!found) {
            puts("No students found with the given name!");
        }
    }
}

// Finds and displays the student(s) with the highest average
void find_class_topper() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    float highest_average = 0.0;

    for (int i = 0; i < count; i++) {
        if (Students[i].average > highest_average) {
            highest_average = Students[i].average;
        }
    }

    puts("Class Topper(s):");
    for (int i = 0; i < count; i++) {
        if (Students[i].average == highest_average) {
            printf("ID: %d, Name: %s %s, Average: %.1f\n",
                   Students[i].ID, Students[i].Fname, Students[i].Lname, Students[i].average);
        }
    }
}

// Displays the distribution of grades in the class
void display_grade_distribution() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    int grade_count[5] = {0}; // A+, A, B, C, D
    int fail_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(Students[i].grade, "A+") == 0) grade_count[0]++;
        else if (strcmp(Students[i].grade, "A") == 0) grade_count[1]++;
        else if (strcmp(Students[i].grade, "B") == 0) grade_count[2]++;
        else if (strcmp(Students[i].grade, "C") == 0) grade_count[3]++;
        else if (strcmp(Students[i].grade, "D") == 0) grade_count[4]++;
        else fail_count++;
    }

    printf("Grade Distribution:\n");
    printf("A+: %d\n", grade_count[0]);
    printf("A: %d\n", grade_count[1]);
    printf("B: %d\n", grade_count[2]);
    printf("C: %d\n", grade_count[3]);
    printf("D: %d\n", grade_count[4]);
    printf("F: %d\n", fail_count);
}

// Allows the user to update the marks for a student
void update_marks() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    int search;
    if (!read_integer("Enter Student ID: !_ ", &search, 1, 9999)) {
        return;
    }

    for (int i = 0; i < count; i++) {
        if (Students[i].ID == search) {
            for (int j = 1; j <= 5; j++) {
                char prompt[50];
                snprintf(prompt, sizeof(prompt), "Enter Mark for Subject %d (0-100): !_ ", j);
                int mark;
                read_integer(prompt, &mark, 0, 100);

                switch (j) {
                    case 1: Students[i].Mark_1 = mark; break;
                    case 2: Students[i].Mark_2 = mark; break;
                    case 3: Students[i].Mark_3 = mark; break;
                    case 4: Students[i].Mark_4 = mark; break;
                    case 5: Students[i].Mark_5 = mark; break;
                }
            }

            Students[i].total = Students[i].Mark_1 + Students[i].Mark_2 + Students[i].Mark_3 + Students[i].Mark_4 + Students[i].Mark_5;
            Students[i].average = (float)Students[i].total / 5;
            calculate_grade(&Students[i]);
            puts("Marks Updated Successfully!!");
            return;
        }
    }

    puts("Student ID not found!");
}

// Displays overall class performance statistics
void display_class_performance() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    int fail_count = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(Students[i].grade, "F") == 0) {
            fail_count++;
        }
    }

    float class_average = 0;
    for (int i = 0; i < count; i++) {
        class_average += Students[i].average;
    }
    class_average /= count;

    float pass_percentage = ((float)(count - fail_count) / count) * 100;

    puts("Class Performance Summary:");
    printf("Average Marks: %.1f\n", class_average);
    printf("Pass Percentage: %.1f%%\n", pass_percentage);
    printf("Failing Students: %d\n", fail_count);
}

// Calculates the letter grade based on the average
void calculate_grade(struct Student* student) {
    if (student->average >= 95) strcpy(student->grade, "A+");
    else if (student->average >= 85) strcpy(student->grade, "A");
    else if (student->average >= 75) strcpy(student->grade, "B");
    else if (student->average >= 65) strcpy(student->grade, "C");
    else if (student->average >= 50) strcpy(student->grade, "D");
    else strcpy(student->grade, "F");
}

// Frees the dynamically allocated memory
void free_memory() {
    free(Students);
    Students = NULL; 
}

// Function to save student data to a file
void save_data(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%d,%d,%d,%d,%d,%d,%f,%s\n",
                Students[i].ID, Students[i].Fname, Students[i].Lname,
                Students[i].Mark_1, Students[i].Mark_2, Students[i].Mark_3,
                Students[i].Mark_4, Students[i].Mark_5, Students[i].total,
                Students[i].average, Students[i].grade);

    }
    fclose(file);
    printf("Data saved to file.\n");
}

// Function to load student data from a file
void load_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }

    // Check if the file is empty before proceeding
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size == 0) {
        printf("The file is empty.\n");
        fclose(file);
        return;
    }
    rewind(file);

    // Read the number of students
    if (fscanf(file, "%d\n", &count) != 1 || count < 0) {
        printf("Invalid number of students in the file.\n");
        fclose(file);
        return;
    }

    // Allocate memory for students based on the count
    Students = (struct Student*)malloc(count * sizeof(struct Student));
    if (Students == NULL) {
        printf("Memory allocation failed during load.\n");
        fclose(file);
        return;
    }

    // Read student data
    for (int i = 0; i < count; i++) {
        int result = fscanf(file, "%d,%49[^,],%49[^,],%d,%d,%d,%d,%d,%d,%f,%2s\n",
                            &Students[i].ID, Students[i].Fname, Students[i].Lname,
                            &Students[i].Mark_1, &Students[i].Mark_2, &Students[i].Mark_3,
                            &Students[i].Mark_4, &Students[i].Mark_5, &Students[i].total,
                            &Students[i].average, Students[i].grade);

        // Debugging: Print fscanf result for each student
        printf("fscanf returned: %d for student %d\n", result, i);

        // Check if fscanf reads the expected number of items (11)
        if (result != 11) {
            printf("Error reading student data for student %d.\n", i);
            free(Students);
            fclose(file);
            return;
        }

        // Calculate the grade after reading the data
        calculate_grade(&Students[i]);
    }

    fclose(file);
    printf("Data loaded from file.\n");
}

// Sort students by total marks or names alphabetically
void sort_students() {
    if (count == 0) {
        puts("No Students Entered!!");
        return;
    }

    int sort_option;
    puts("\nSorting Options:");
    puts("1. Sort by Total Marks");
    puts("2. Sort by Name (Alphabetically)");
    if (!read_integer("Enter your choice: !_ ", &sort_option, 1, 2)) {
        return;
    }

    switch (sort_option) {
        case 1:
            // Sort by Total Marks (Descending)
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (Students[j].total < Students[j + 1].total) {
                        struct Student temp = Students[j];
                        Students[j] = Students[j + 1];
                        Students[j + 1] = temp;
                    }
                }
            }
            puts("Students sorted by total marks (highest to lowest).");
            break;

        case 2:
            // Sort by Name (Alphabetically)
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (strcmp(Students[j].Fname, Students[j + 1].Fname) > 0) {
                        struct Student temp = Students[j];
                        Students[j] = Students[j + 1];
                        Students[j + 1] = temp;
                    } else if (strcmp(Students[j].Fname, Students[j + 1].Fname) == 0) {
                        // If first names are equal, compare last names
                        if (strcmp(Students[j].Lname, Students[j + 1].Lname) > 0) {
                            struct Student temp = Students[j];
                            Students[j] = Students[j + 1];
                            Students[j + 1] = temp;
                        }
                    }
                }
            }
            puts("Students sorted by name (alphabetically).");
            break;

        default:
            puts("Invalid choice!");
            return;
    }

    // Display sorted students
    display_all_students();
}
