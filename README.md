# MiniRelationalDB – Lightweight Relational Database Engine (C++)

A lightweight command-line relational database engine built entirely in C++. It supports SQL-like operations such as `CREATE TABLE`, `INSERT INTO`, and `SELECT * FROM`, all stored persistently using file I/O in `.tbl` files.

---

##  Features

-  Create and manage custom tables
-  Insert new rows into tables
-  Query tables with `SELECT * FROM`
-  File-based persistent storage in CSV-style `.tbl` format
-  Modular object-oriented design with parser, table engine, and utility helpers

---

## 📂 Project Structure

```
MiniRelationalDB/
├── main.cpp                  # Entry point
├── Makefile                  # (Optional) Build script
├── engine/                   # Database engine modules
│   ├── Table.h/.cpp          # Table schema and data
│   ├── Parser.h/.cpp         # Command interpreter
│   └── Utils.h/.cpp          # Tokenization and string utilities
├── db/                       # Stores .tbl files
└── README.md                 # This file
```

---

## 🧱 Prerequisites

- g++ compiler with C++17 support
- Windows (MSYS2, MinGW) or Linux/macOS

---

## ⚙️ Build Instructions

### 🔁 Without `make` (Manual Build)

```bash
cd MiniRelationalDB
mkdir db     # Only needed once

# Compile
g++ -std=c++17 -Iengine main.cpp engine/*.cpp -o minidb.exe

# Run
./minidb.exe
```

---

## 🧪 Sample CLI Usage

```sql
CREATE TABLE students (id, name, age)
INSERT INTO students VALUES (1, Alice, 20)
INSERT INTO students VALUES (2, Bob, 22)
SELECT * FROM students
```

Expected Output:
```
id      name    age
1       Alice   20
2       Bob     22
```

---

## 📦 Table File Format

Files are stored under the `db/` directory, one per table.
Example: `db/students.tbl`
```
id,name,age
1,Alice,20
2,Bob,22
```

---

## 📚 Concepts Demonstrated

- ✅ Custom command parsing
- ✅ File I/O using `fstream`
- ✅ CLI design and input parsing
- ✅ Vectors and string manipulation
- ✅ Object-oriented design in C++

---

## 🧠 Future Enhancements

- Support `WHERE` clause filters
- Implement `DELETE` and `UPDATE`
- Add JOIN operations
- Add indexing with hash maps or B+ trees
- Improve error handling and data typing

---

## 👨‍💻 Author

**Shashank Sonawane**  
📧 shashanksonawane2213@gmail.com  
🔗 [LinkedIn](https://linkedin.com/in/shashank-sonawane-16919a1a8)  
🔗 [GitHub](https://github.com/ShashankS2213)

---
