# Library Management System

This is a simple Library Management System implemented in C++. It allows users to manage a collection of books and users, facilitating tasks such as adding books, searching for books by name prefix, borrowing and returning books, and more.

## Features

- Add a Book: Users can add books to the library system by providing book information such as ID, name, and total quantity.

- Search Books by Prefix: Users can search for books based on a name prefix, helping them find relevant books efficiently.

- Print Users Who Borrowed a Book by Name: Retrieve a list of users who have borrowed a specific book.

- Print Library by ID: Display the entire library collection sorted by book ID.

- Print Library by Name: Display the entire library collection sorted by book name.

- Add a User: Users can add new members to the system by providing user information like name and national ID.

- User Borrow a Book: Allow users to borrow a book, updating both the book's availability and the user's borrowed book list.

- User Return a Book: Enable users to return a book, updating the book's availability and the user's borrowed book list.

- Print Users: Display a list of all users along with the books they have borrowed.

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/Ragdha-Elgaidi/library-management-system.git
    ```

2. Compile the program:

    ```bash
    g++ library system.cpp -o library system
    ```

3. Run the program:

    ```bash
    ./library system
    ```

4. Follow the on-screen instructions to interact with the Library Management System.
