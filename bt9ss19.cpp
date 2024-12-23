#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char fullName[50];
    int age;
    char numberPhone[50];
} Student;

void printStudents(Student students[], int size);
void addStudent(Student students[], int *size);
void editStudent(Student students[], int size);
void deleteStudent(Student students[], int *size);
void searchStudent(Student students[], int size);
void sortStudentsByName(Student students[], int size);

int main() {
    Student students[50] = {
        {1, "Dao Xuan Khanh", 18, "0936123456"},
        {2, "Tran Van A", 90, "0653496849"},
        {3, "Nguyen Van B", 78, "0938284323"},
        {4, "Le Van C", 99, "0394258454"},
        {5, "Tong Gia N", 34, "0594385659"},
    };
    int size = 5;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien moi\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep sinh vien theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printStudents(students, size);
                break;
            case 2:
                addStudent(students, &size);
                break;
            case 3:
                editStudent(students, size);
                break;
            case 4:
                deleteStudent(students, &size);
                break;
            case 5:
                searchStudent(students, size);
                break;
            case 6:
                sortStudentsByName(students, size);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

void printStudents(Student students[], int size) {
    if (size == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ho va ten: %s\n", students[i].fullName);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n\n", students[i].numberPhone);
    }
}

void addStudent(Student students[], int *size) {
    if (*size >= 50) {
        printf("Danh sach da day. Khong the them sinh vien moi.\n");
        return;
    }
    Student newStudent;
    newStudent.id = *size + 1;
    printf("Nhap ho va ten: ");
    fgets(newStudent.fullName, sizeof(newStudent.fullName), stdin);
    newStudent.fullName[strcspn(newStudent.fullName, "\n")] = '\0';
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Nhap so dien thoai: ");
    fgets(newStudent.numberPhone, sizeof(newStudent.numberPhone), stdin);
    newStudent.numberPhone[strcspn(newStudent.numberPhone, "\n")] = '\0';
    students[*size] = newStudent;
    (*size)++;
    printf("Da them sinh vien moi thanh cong.\n");
}

void editStudent(Student students[], int size) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Nhap ho va ten moi: ");
            fgets(students[i].fullName, sizeof(students[i].fullName), stdin);
            students[i].fullName[strcspn(students[i].fullName, "\n")] = '\0';
            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            getchar();
            printf("Nhap so dien thoai moi: ");
            fgets(students[i].numberPhone, sizeof(students[i].numberPhone), stdin);
            students[i].numberPhone[strcspn(students[i].numberPhone, "\n")] = '\0';
            printf("Da cap nhat thong tin sinh vien thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}

void deleteStudent(Student students[], int *size) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j + 1];
            }
            (*size)--;
            printf("Da xoa sinh vien thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}

void searchStudent(Student students[], int size) {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    for (int i = 0; i < size; i++) {
        if (strstr(students[i].fullName, name) != NULL) {
            printf("ID: %d\n", students[i].id);
            printf("Ho va ten: %s\n", students[i].fullName);
            printf("Tuoi: %d\n", students[i].age);
            printf("So dien thoai: %s\n\n", students[i].numberPhone);
        }
    }
}

void sortStudentsByName(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].fullName, students[j].fullName) > 0) {
                Student temp = students[i];
                students[i] = temp;
            }
        }
    }
    printf("Danh sach da duoc sap xep theo ten.\n");
}

