#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 30;

// 输入学生数据
int inputStudentData(int studentIds[], int scores[]) {
    int count = 0;
    int id, score;
    
    cout << "请输入学生学号和成绩（输入负数结束）：" << endl;
    cout << "学号 成绩 学号 成绩 学号 成绩 学号 成绩" << endl;
    
    while (count < MAX_STUDENTS) {
        cin >> id >> score;
        if (id < 0 || score < 0) {
            break;
        }
        studentIds[count] = id;
        scores[count] = score;
        count++;
    }
    
    return count;
}

// 统计不及格人数并打印名单
void printFailingStudents(int studentIds[], int scores[], int count) {
    int failCount = 0;
    cout << "不及格人数：";
    
    // 先统计人数
    for (int i = 0; i < count; i++) {
        if (scores[i] < 60) {
            failCount++;
        }
    }
    
    cout << failCount << " 名单：";
    
    // 打印不及格学生学号
    bool first = true;
    for (int i = 0; i < count; i++) {
        if (scores[i] < 60) {
            if (!first) cout << ",";
            cout << studentIds[i];
            first = false;
        }
    }
    cout << endl;
}

// 计算平均分
double calculateAverage(int scores[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum / count;
}

// 打印平均分及以上的学生
void printAboveAverageStudents(int studentIds[], int scores[], int count, double average) {
    cout << "平均分：" << fixed << setprecision(1) << average << endl;
    cout << "平均分及平均分之上的学生:";
    
    bool first = true;
    for (int i = 0; i < count; i++) {
        if (scores[i] >= average) {
            if (!first) cout << ",";
            cout << studentIds[i];
            first = false;
        }
    }
    cout << endl;
}

// 统计各分数段
void printGradeDistribution(int scores[], int count) {
    int grade0_59 = 0;   // 不及格
    int grade60_69 = 0;  // 60-69
    int grade70_79 = 0;  // 70-79
    int grade80_89 = 0;  // 80-89
    int grade90_100 = 0; // 90-100
    
    for (int i = 0; i < count; i++) {
        if (scores[i] < 60) {
            grade0_59++;
        } else if (scores[i] < 70) {
            grade60_69++;
        } else if (scores[i] < 80) {
            grade70_79++;
        } else if (scores[i] < 90) {
            grade80_89++;
        } else {
            grade90_100++;
        }
    }
    
    cout << fixed << setprecision(1);
    cout << "不及格:" << (grade0_59 * 100.0 / count) << "% ";
    cout << "60-69分:" << (grade60_69 * 100.0 / count) << "% ";
    cout << "70-79分:" << (grade70_79 * 100.0 / count) << "% ";
    cout << "80-89分:" << (grade80_89 * 100.0 / count) << "% ";
    cout << "90-100分:" << (grade90_100 * 100.0 / count) << "%" << endl;
}

int main() {
    int studentIds[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    
    // 输入学生数据
    int studentCount = inputStudentData(studentIds, scores);
    
    if (studentCount == 0) {
        cout << "没有输入有效数据！" << endl;
        return 0;
    }
    
    // 统计不及格人数
    printFailingStudents(studentIds, scores, studentCount);
    
    // 计算平均分并打印平均分及以上的学生
    double average = calculateAverage(scores, studentCount);
    printAboveAverageStudents(studentIds, scores, studentCount, average);
    
    // 统计各分数段
    printGradeDistribution(scores, studentCount);
    
    return 0;
}

