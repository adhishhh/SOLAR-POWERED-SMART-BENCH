#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENT_COUNT 100

typedef struct {
    int studentID;
    bool present;
} StudentAttendance;

void initializeStudentAttendance(StudentAttendance* attendance, int studentCount);
void markStudentPresent(StudentAttendance* attendance, int studentID);

int main() {
    int studentCount;
    int studentID;
    
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);
    
    StudentAttendance attendance[MAX_STUDENT_COUNT];
    initializeStudentAttendance(attendance, studentCount);
    
    printf("Enter the student ID to mark as present: ");
    scanf("%d", &studentID);
    
    markStudentPresent(attendance, studentID);
    
    return 0;
}

void initializeStudentAttendance(StudentAttendance* attendance, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        attendance[i].studentID = i + 1;
        attendance[i].present = false;
    }
}

void markStudentPresent(StudentAttendance* attendance, int studentID) {
    for (int i = 0; i < MAX_STUDENT_COUNT; i++) {
        if (attendance[i].studentID == studentID) {
            attendance[i].present = true;
            printf("Student with ID %d marked as present.\n", studentID);
            return;
        }
    }
    
    printf("Student with ID %d not found.\n", studentID);
}
