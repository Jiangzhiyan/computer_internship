#include "student.h"

using namespace std;

// 清屏函数
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// 显示主菜单
void showMenu() {
    cout << "《学生成绩管理系统》" << endl;
    cout << "[0]新生注册" << endl;
    cout << "[1]选课登记" << endl;
    cout << "[2]学生成绩输入" << endl;
    cout << "[3]成绩查询" << endl;
    cout << "[4]修改成绩" << endl;
    cout << "[5]退出" << endl;
}

// 注册新生
void registerStudent(Student*& head) {
    cout << "学号 姓名" << endl;
    int id;
    string name;
    int count = 0;
    
    while (cin >> id && id != -1) {
        cin >> name;
        
        // 创建新学生节点
        Student* newStudent = new Student;
        newStudent->id = id;
        newStudent->name = name;
        newStudent->next = nullptr;
        
        // 插入到链表
        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
        count++;
    }
    
    cout << "学生数据库共有" << count << "个记录" << endl;
    cout << "继续新的注册? ";
    char choice;
    cin >> choice;
    clearScreen();
}

// 查找学生
Student* findStudent(Student* head, int id) {
    Student* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// 获取学生姓名
string getStudentName(Student* head, int id) {
    Student* student = findStudent(head, id);
    if (student != nullptr) {
        return student->name;
    }
    return "";
}

// 选课登记
void enrollCourse(Student* studentHead, CourseEnrollment*& enrollHead) {
    char continueChoice = 'y';
    
    while (continueChoice == 'y' || continueChoice == 'Y') {
        int courseId;
        cout << "课程号：";
        cin >> courseId;
        
        cout << "输入选择该课程的学生学号:" << endl;
        int studentId;
        int count = 0;
        
        while (cin >> studentId && studentId != -1) {
            // 检查学生是否存在
            if (findStudent(studentHead, studentId) != nullptr) {
                // 创建新的选课记录
                CourseEnrollment* newEnroll = new CourseEnrollment;
                newEnroll->courseId = courseId;
                newEnroll->studentId = studentId;
                newEnroll->grade = -1;  // 初始成绩为-1
                newEnroll->next = nullptr;
                
                // 插入到链表
                if (enrollHead == nullptr) {
                    enrollHead = newEnroll;
                } else {
                    CourseEnrollment* current = enrollHead;
                    while (current->next != nullptr) {
                        current = current->next;
                    }
                    current->next = newEnroll;
                }
                count++;
            }
        }
        
        cout << "共有" << count << "个学生选此课程" << endl;
        cout << "继续新的选课输入? ";
        cin >> continueChoice;
    }
    
    clearScreen();
}

// 输入成绩
void inputGrades(Student* studentHead, CourseEnrollment* enrollHead) {
    char continueChoice = 'y';
    
    while (continueChoice == 'y' || continueChoice == 'Y') {
        int courseId;
        cout << "课程号：";
        cin >> courseId;
        
        // 查找该课程的所有学生
        CourseEnrollment* current = enrollHead;
        bool found = false;
        
        while (current != nullptr) {
            if (current->courseId == courseId && current->grade == -1) {
                found = true;
                string studentName = getStudentName(studentHead, current->studentId);
                cout << "学号：" << current->studentId << " 姓名：" << studentName << " 成绩：";
                cin >> current->grade;
            }
            current = current->next;
        }
        
        if (found) {
            cout << courseId << "课程成绩已输入完成" << endl;
        } else {
            cout << "没有找到该课程或成绩已录入" << endl;
        }
        
        cout << "继续其他课程成绩输入? ";
        cin >> continueChoice;
    }
    
    clearScreen();
}

// 查询成绩
void queryGrades(Student* studentHead, CourseEnrollment* enrollHead) {
    char continueChoice = 'y';
    
    while (continueChoice == 'y' || continueChoice == 'Y') {
        int studentId;
        cout << "学号：";
        cin >> studentId;
        
        Student* student = findStudent(studentHead, studentId);
        if (student != nullptr) {
            cout << "姓名：" << student->name << " 成绩:" << endl;
            
            CourseEnrollment* current = enrollHead;
            while (current != nullptr) {
                if (current->studentId == studentId && current->grade != -1) {
                    cout << "课程号：" << current->courseId << " 成绩：" << current->grade << endl;
                }
                current = current->next;
            }
        } else {
            cout << "未找到该学生" << endl;
        }
        
        cout << "继续查询？";
        cin >> continueChoice;
    }
    
    clearScreen();
}

// 修改成绩
void modifyGrades(CourseEnrollment* enrollHead) {
    char continueChoice = 'y';
    
    while (continueChoice == 'y' || continueChoice == 'Y') {
        int studentId, courseId;
        cout << "学号：";
        cin >> studentId;
        cout << "课程号：";
        cin >> courseId;
        
        // 查找对应的选课记录
        CourseEnrollment* current = enrollHead;
        bool found = false;
        
        while (current != nullptr) {
            if (current->studentId == studentId && current->courseId == courseId) {
                found = true;
                cout << "原成绩：" << current->grade << " 成绩修改为：";
                cin >> current->grade;
                break;
            }
            current = current->next;
        }
        
        if (!found) {
            cout << "未找到该学生的该门课程成绩" << endl;
        }
        
        cout << "继续修改? ";
        cin >> continueChoice;
    }
    
    clearScreen();
}

// 释放内存
void freeMemory(Student* studentHead, CourseEnrollment* enrollHead) {
    // 释放学生链表
    while (studentHead != nullptr) {
        Student* temp = studentHead;
        studentHead = studentHead->next;
        delete temp;
    }
    
    // 释放选课链表
    while (enrollHead != nullptr) {
        CourseEnrollment* temp = enrollHead;
        enrollHead = enrollHead->next;
        delete temp;
    }
}

// 主函数
int main() {
    Student* studentHead = nullptr;
    CourseEnrollment* enrollHead = nullptr;
    int command;
    
    clearScreen();
    
    while (true) {
        showMenu();
        cout << "命令？";
        cin >> command;
        
        switch (command) {
            case 0:
                registerStudent(studentHead);
                break;
            case 1:
                enrollCourse(studentHead, enrollHead);
                break;
            case 2:
                inputGrades(studentHead, enrollHead);
                break;
            case 3:
                queryGrades(studentHead, enrollHead);
                break;
            case 4:
                modifyGrades(enrollHead);
                break;
            case 5:
                freeMemory(studentHead, enrollHead);
                return 0;
            default:
                cout << "无效命令！" << endl;
        }
    }
    
    return 0;
}