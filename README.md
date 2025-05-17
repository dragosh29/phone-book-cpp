# Phone Book Management System (C++)

This project is a C++ phone book management system that applies Object-Oriented Programming principles. It allows users to manage contacts through an interactive menu, supporting operations like add, display, search, delete, modify, and reset. All data is persisted using a local text file.

## Features

- Add a new contact  
- Display all saved contacts  
- Search by telephone number substring  
- Modify contact details  
- Delete a contact by number  
- Reset the entire phone book  

## Technologies

- C++23  
- STL (`std::vector`)  
- File I/O via `fstream`  
- Terminal I/O (`cin`, `cout`)  
- CMake for build automation  

## Build Instructions

To build and run the project:

```
git clone https://github.com/dragosh29/phone-book-cpp.git
cd phone-book-cpp
mkdir build
cd build
cmake ..
make
./phone_book_c__
```

## Notes

- Contact data is stored in a plain text file: `input.txt`  
- Includes basic CLI-based input handling  
- Uses `system("cls")` and `system("pause")` for console management (Windows-specific)  
  - On Linux/macOS, these calls may need to be removed or replaced  

## License

This project is licensed under the MIT License.
