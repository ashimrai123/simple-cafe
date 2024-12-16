# Cafe Management System in C++

## Description

A simple console-based Cafe Management System developed in C++. The system allows the management of menu items, taking orders, generating bills, and more.

## How to Run

### Prerequisites

- You need to have **g++** (GNU Compiler Collection) installed to compile the C++ code.
- A terminal or command prompt to run the commands.
- **PostgreSQL** installed and running, or use NeonDB for the database.

### Steps to Run the Project

1. **Clone the repository**:

   ```terminal
   git clone https://github.com/ashimrai123/simple-cafe.git
   ```

2. **Navigate into the project directory**:

   ```terminal
   cd simple-cafe
   ```

3. **Create the build directory** (if it doesn't exist):

   ```terminal
   mkdir build
   ```

4. **Compile the source code**:

   On **Windows** (make sure to replace paths according to your setup):

   ```terminal
   g++ src/*.cpp -o build/CafeSystem.exe -I"C:/Program Files/PostgreSQL/16/include" -L"C:/Program Files/PostgreSQL/16/lib" -lpq
   ```

   On **Linux/macOS**:

   ```terminal
   g++ src/*.cpp -o build/CafeSystem -lpq
   ```

5. **Set up the database**:

   - Before running the program, you need to create the required table in your database.
   - For **NeonDB**, execute the following SQL to create the `orders` table:

   ```sql
   CREATE TABLE orders (
       id SERIAL PRIMARY KEY,
       menu_item_id INT,
       quantity INT,
       total_price NUMERIC,
       order_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
   );
   ```

6. **Run the program**:

   On **Windows**:

   ```terminal
   build\CafeSystem.exe
   ```

   On **Linux/macOS**:

   ```terminal
   ./build/CafeSystem
   ```

### Environment Setup for Database Connection

- In the `main.cpp` file, replace the database connection string with your own NeonDB connection string. You can set this using environment variables or directly in the code (not recommended for production).

  Example:

  ```cpp
  std::string connInfo = "postgresql://your_db_user:your_db_password@your_db_host:port/your_db_name?sslmode=require";
  ```

- For environment variables (recommended for security), you can use:

  ```cpp
  const char *connInfo = std::getenv("DB_CONNECTION_STRING");
  ```

  Then set the environment variable `DB_CONNECTION_STRING` before running the application.
