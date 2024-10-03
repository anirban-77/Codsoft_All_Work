#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::cin.ignore();
    std::getline(std::cin, taskDescription);
    tasks.push_back({taskDescription, false});
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description 
                  << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
    std::cout << std::endl;
}

void markTaskAsCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
