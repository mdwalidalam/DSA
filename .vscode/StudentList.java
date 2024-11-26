import java.io.*;
import java.text.*;
import java.util.*;

public class StudentList {
    // Constants
    private static final String FILE_NAME = "students.txt";
    private static final String DATE_FORMAT = "dd/MM/yyyy-hh:mm:ss a";
    private static final String DATA_LOADED_MSG = "Data Loaded.";
    private static final String LOADING_MSG = "Loading data ...";

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No arguments provided. Please use a valid argument.");
            return;
        }

        String operation = args[0];

        switch (operation.charAt(0)) {
            case 'a':
                displayAllStudents();
                break;
            case 'r':
                displayRandomStudent();
                break;
            case '+':
                addStudent(operation.substring(1));
                break;
            case '?':
                searchStudent(operation.substring(1));
                break;
            case 'c':
                countWords();
                break;
            default:
                System.out.println("Invalid argument. Please use one of the following: a, r, +<name>, ?<name>, or c.");
        }
    }

    private static void displayAllStudents() {
        System.out.println(LOADING_MSG);
        try {
            String data = readFromFile();
            String[] students = data.split(", ");
            for (String student : students) {
                System.out.println(student);
            }
        } catch (Exception e) {
            System.err.println("Error loading data: " + e.getMessage());
        }
        System.out.println(DATA_LOADED_MSG);
    }

    private static void displayRandomStudent() {
        System.out.println(LOADING_MSG);
        try {
            String data = readFromFile();
            String[] students = data.split(", ");
            Random random = new Random();
            int randomIndex = random.nextInt(students.length);
            System.out.println(students[randomIndex]);
        } catch (Exception e) {
            System.err.println("Error loading data: " + e.getMessage());
        }
        System.out.println(DATA_LOADED_MSG);
    }

    private static void addStudent(String newStudent) {
        System.out.println(LOADING_MSG);
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true));
            String timestamp = new SimpleDateFormat(DATE_FORMAT).format(new Date());
            writer.write(", " + newStudent + "\nList last updated on " + timestamp);
            writer.close();
        } catch (Exception e) {
            System.err.println("Error writing data: " + e.getMessage());
        }
        System.out.println(DATA_LOADED_MSG);
    }

    private static void searchStudent(String studentName) {
        System.out.println(LOADING_MSG);
        try {
            String data = readFromFile();
            String[] students = data.split(", ");
            if (Arrays.asList(students).contains(studentName)) {
                System.out.println("We found it!");
            } else {
                System.out.println("Student not found.");
            }
        } catch (Exception e) {
            System.err.println("Error searching data: " + e.getMessage());
        }
        System.out.println(DATA_LOADED_MSG);
    }

    private static void countWords() {
        System.out.println(LOADING_MSG);
        try {
            String data = readFromFile();
            String[] words = data.split(", ");
            System.out.println(words.length + " word(s) found");
        } catch (Exception e) {
            System.err.println("Error counting words: " + e.getMessage());
        }
        System.out.println(DATA_LOADED_MSG);
    }

    private static String readFromFile() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(FILE_NAME)));
        String data = reader.readLine();
        reader.close();
        return data;
    }
}


