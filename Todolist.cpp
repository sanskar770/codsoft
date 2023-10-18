#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void addTask() {
    Task task;
    std::cout << "Enter the task you want to add: ";
    std::cin.ignore();
    std::getline(std::cin, task.description);
    task.completed = false;
    tasks.push_back(task);
    std::cout << "Task added successfully!" << std::endl;
}

void viewTasks() {
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::string status = (tasks[i].completed) ? "Completed" : "Pending";
        std::cout << i + 1 << ". " << tasks[i].description << " - " << status << std::endl;
    }
}

void markCompleted() {
    viewTasks();
    int taskIndex;
    std::cout << "Enter the number of the task you want to mark as completed: ";
    std::cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask() {
    viewTasks();
    int taskIndex;
    std::cout << "Enter the number of the task you want to remove: ";
    std::cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "\nTodo List Manager Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
