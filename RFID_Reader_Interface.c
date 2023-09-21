#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENT_ID_LENGTH 20

typedef struct {
    char studentID[MAX_STUDENT_ID_LENGTH];
    bool authenticated;
} Student;

void initializeStudent(Student* student);
bool readRFIDCard(Student* student, const char* cardData);

int main() {
    Student student;
    initializeStudent(&student);
    
    char cardData[MAX_STUDENT_ID_LENGTH];
    
    printf("Please scan your RFID card: ");
    scanf("%s", cardData);
    
    if (readRFIDCard(&student, cardData)) {
        printf("Authentication successful. Welcome, %s!\n", student.studentID);
    } else {
        printf("Authentication failed. Please try again.\n");
    }
    
    return 0;
}

void initializeStudent(Student* student) {
    memset(student->studentID, 0, sizeof(student->studentID));
    student->authenticated = false;
}

bool readRFIDCard(Student* student, const char* cardData) {
    const char* validStudentID = "12345";
    
    if (strcmp(cardData, validStudentID) == 0) {
        strncpy(student->studentID, cardData, sizeof(student->studentID));
        student->authenticated = true;
        return true;
    } else {
        return false;
    }
}
