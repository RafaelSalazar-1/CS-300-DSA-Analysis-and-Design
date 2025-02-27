#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

// Define the Course structure
struct Course {
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;
};

// Function to convert a string to uppercase
std::string toUpperCase(const std::string& str) {
    std::string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

// Function to load courses from a file
std::vector<Course> loadCourses(const std::string& fileName) {
    std::vector<Course> courses;
    std::ifstream file(fileName);
    std::string line;

    if (!file) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return courses;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        std::istringstream ss(line);
        Course course;
        std::getline(ss, course.courseNumber, ',');
        std::getline(ss, course.courseTitle, ',');

        std::string prereq;
        while (std::getline(ss, prereq, ',')) {
            if (!prereq.empty()) {
                course.prerequisites.push_back(prereq);
            }
        }
        courses.push_back(course);
    }

    return courses;
}

// Function to display the menu
void displayMenu() {
    std::cout << "1. Load Data Structure.\n";
    std::cout << "2. Print Course List.\n";
    std::cout << "3. Print Course.\n";
    std::cout << "9. Exit\n";
}

// Function to print the course list
void printCourseList(const std::vector<Course>& courses) {
    std::vector<Course> sortedCourses = courses;
    std::sort(sortedCourses.begin(), sortedCourses.end(),  {
        return a.courseNumber < b.courseNumber;
    });

    for (const auto& course : sortedCourses) {
        std::cout << course.courseNumber << ", " << course.courseTitle << std::endl;
    }
}

// Function to print course information
void printCourseInfo(const std::vector<Course>& courses, const std::string& courseNumber) {
    std::string upperCourseNumber = toUpperCase(courseNumber);
    for (const auto& course : courses) {
        if (toUpperCase(course.courseNumber) == upperCourseNumber) {
            std::cout << course.courseNumber << ", " << course.courseTitle << std::endl;
            std::cout << "Prerequisites: ";
            for (const auto& prereq : course.prerequisites) {
                std::cout << prereq << " ";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Course not found." << std::endl;
}

// Main function
int main() {
    int choice;
    std::vector<Course> courses;

    do {
        displayMenu();
        std::cout << "What would you like to do? ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string fileName;
                std::cout << "Enter the course data file name: ";
                std::cin >> fileName;
                courses = loadCourses(fileName);
                break;
            }
            case 2:
                printCourseList(courses);
                break;
            case 3: {
                std::string courseNumber;
                std::cout << "What course do you want to know about? ";
                std::cin >> courseNumber;
                printCourseInfo(courses, courseNumber);
                break;
            }
            case 9:
                std::cout << "Thank you for using the course planner!\n";
                break;
            default:
                std::cout << choice << " is not a valid option.\n";
        }
    } while (choice != 9);

    return 0;
}