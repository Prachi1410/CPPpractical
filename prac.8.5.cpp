#include <iostream>
#include <vector>
#include <string>

struct Folder {
    std::string name;
    std::vector<std::string> files;
};

class DirectoryManager {
private:
    std::vector<Folder> folders;

    // Manual bubble sort for folder names
    void sortFolders() {
        int n = folders.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (folders[j].name > folders[j + 1].name) {
                    std::swap(folders[j], folders[j + 1]);
                }
            }
        }
    }

public:
    // Add a new folder if it doesn't exist
    void addFolder(const std::string& folderName) {
        for (const auto& folder : folders) {
            if (folder.name == folderName) {
                std::cout << "Folder '" << folderName << "' already exists.\n";
                return;
            }
        }

        Folder newFolder;
        newFolder.name = folderName;
        folders.push_back(newFolder);
        std::cout << "Folder '" << folderName << "' created.\n";

        sortFolders(); // Maintain alphabetical order
    }

    // Add a file to a specific folder
    void addFileToFolder(const std::string& folderName, const std::string& fileName) {
        for (auto& folder : folders) {
            if (folder.name == folderName) {
                folder.files.push_back(fileName);
                std::cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
                return;
            }
        }
        std::cout << "Folder '" << folderName << "' not found.\n";
    }

    // Display the entire directory structure
    void displayDirectory() const {
        std::cout << "\nDirectory Structure:\n";
        for (const auto& folder : folders) {
            std::cout << "📁 " << folder.name << ":\n";
            for (const auto& file : folder.files) {
                std::cout << "    - " << file << "\n";
            }
        }
    }
};

// Example usage
int main() {
    DirectoryManager dm;

    dm.addFolder("src");
    dm.addFolder("docs");
    dm.addFolder("tests");

    dm.addFileToFolder("src", "main.cpp");
    dm.addFileToFolder("src", "utils.cpp");
    dm.addFileToFolder("docs", "README.md");
    dm.addFileToFolder("tests", "test_main.cpp");

    dm.displayDirectory();

    return 0;
}

