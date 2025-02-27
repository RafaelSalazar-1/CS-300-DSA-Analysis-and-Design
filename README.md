# CS-300-DSA-Analysis-and-Design

Advising Assistance Program
Overview
This project is designed to assist academic advisors in the Computer Science department at ABCU by providing a command-line program to manage and display course information. The program reads course data from a file, stores it in a data structure, and allows users to interact with the data through a menu-driven interface.
Problem Statement
The primary problem addressed in this project was to develop a software application that helps academic advisors efficiently manage and retrieve course information. The application needed to load course data from a file, display a list of courses, and provide detailed information about individual courses, including their prerequisites.
Approach
To solve this problem, I designed and implemented a C++ program that uses appropriate data structures to store and manage course information. Data structures are crucial in this context because they determine the efficiency of data retrieval and manipulation operations. I chose a vector to store the course objects due to its simplicity and ease of use for this project.
Pseudocode and Runtime Analysis
The pseudocode and runtime analysis provided in the document guided the implementation. The pseudocode outlined the steps for file handling, data validation, creating and storing course objects, and implementing menu options. The runtime analysis compared the performance of different data structures (vector, hash table, binary search tree) for various operations, ultimately recommending the hash table for its efficiency in search and insertion operations.
Challenges and Solutions
During the project, I encountered several challenges, including handling file input/output, parsing course data, and ensuring the program's robustness. To overcome these challenges, I:
• Implemented error handling for file operations to ensure the program behaves correctly if the file cannot be opened.
• Used string manipulation techniques to parse the course data and handle cases with varying numbers of prerequisites.
• Validated user input to ensure the program handles invalid options gracefully.
Learning and Development
Working on this project has significantly expanded my approach to designing software and developing programs. I learned the importance of choosing the right data structures for specific tasks and how they impact the efficiency and performance of the application. Additionally, I gained experience in writing maintainable, readable, and adaptable code by following industry best practices, such as using meaningful variable names, adding comments, and handling errors gracefully.
Conclusion
This project has been a valuable learning experience, enhancing my understanding of data structures and their applications in software development. The skills and knowledge gained from this project will be instrumental in my future endeavors as a software developer.
