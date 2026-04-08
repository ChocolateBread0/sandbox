# SmartSearch-CPP
A flexible C++ recursive file and directory search tool that generates stylized HTML reports. Originally designed to locate game configuration files, it uses a customizable text file to scan entire drives for specific patterns and extensions.
------------------------------------------

This program was originally created for my own personal purposes, which explains why the source code and internal naming are in Italian. It is a high-performance search utility written in C++17

## Technical Overview
The application operates through the following steps:

1. **Configuration Parsing:** The program starts by reading the exstensions.txt file. It parses the content to distinguish between target folders (cartelle) and files based on specific tags.
2. **Data Sanitization:** During the reading process, the parser is designed to ignore empty lines, spaces, and comments marked with !--.
3. **Recursive Search:** Once the targets are loaded into vectors, the engine performs a recursive scan of the file system (starting from C:\ by default). It searches for matches by checking if the file or folder name contains any of the strings specified in the configuration file.
4. **HTML Reporting:** All matches found during the scan are stored and formatted into an HTML results file.
5. **Automatic Display:** After the analysis is complete, the program automatically opens the generated HTML report using the default system browser.
