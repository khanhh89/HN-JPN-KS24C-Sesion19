#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char fullName[100];
    int age;
    char phone[25];
} Student;

void printStudents(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Id: %d\n", students[i].id);
        printf("Ho va ten: %s\n", students[i].fullName);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n\n", students[i].phone);
    }
}

void sortStudentsByName(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].fullName, students[j].fullName) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    Student students[5] = {
        {1, "Dao Xuan Khanh", 18, "092492403"},
        {2, "Tran Van Cu", 45, "3435845835"},
        {3, "Dao Xuan Kien", 18, "0342684600"},
        {4, "Nguyen Van Bip", 78, "328945835"},
        {5, "Tran Tien Bip", 98, "4590358355"},
    };

    printf("Danh sach sinh vien ban dau la:\n");
    printStudents(students, 5);

    sortStudentsByName(students, 5);

    printf("Danh sach sinh vien sau khi sap xep:\n");
    printStudents(students, 5);

    return 0;
}

