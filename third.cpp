#include <iostream>
#include <string>

using namespace std;

class QuizItem {
public:
    virtual void show() const = 0;
    virtual bool check(int user_answer) const = 0;
    virtual void displayCorrectAnswer() const = 0;
    virtual ~QuizItem() {}
};

class Question : public QuizItem {
public:
    Question(int seq, string q, string o1, string o2, string o3, int a)
        : sequence(seq), question(q), option1(o1), option2(o2), option3(o3), answer(a) {}

    void show() const override {
        cout << "Question " << sequence << ": " << question << endl;
        cout << "1. " << option1 << endl;
        cout << "2. " << option2 << endl;
        cout << "3. " << option3 << endl;
    }

    bool check(int user_answer) const override {
        return user_answer == answer;
    }

    void displayCorrectAnswer() const override {
        cout << "Correct answer: " << answer << ". " << "Explanation: " << option[answer - 1] << endl;
    }

private:
    int sequence;
    string question;
    string option1;
    string option2;
    string option3;
    int answer;
    string option[3] = {option1, option2, option3};
};

class Quiz {
public:
    Quiz(Question items[], int size) : quizItems(items), quizSize(size) {}

    void run() {
        cout << "Welcome to the UN SDG Quiz game! We have built it as our Programming Technique 2 project!" << endl;

        int score = 0;

        for (int i = 0; i < quizSize; ++i) {
            quizItems[i].show();
            
            int user_answer;
            cout << "Enter your answer: ";
            cin >> user_answer;

            if (quizItems[i].check(user_answer)) {
                cout << "Correct! Congratulations!" << endl;
                score++;
            } else {
                cout << "Incorrect. Don't worry, keep going!" << endl;
                quizItems[i].displayCorrectAnswer();
            }
        }
        cout << "Your final score is " << score << " out of  " << quizSize << endl;
    }

private:
    Question* quizItems;
    int quizSize;
};

class Player {
public:
    Player(string n) : name(n) {}

    string get_name() const {
        return name;
    }

private:
    string name;
};

int main() {
    const int numQuestions = 21;
    Question quizArray[numQuestions] = {
        Question(1, "What is the goal of SDG 17?", "To end poverty", "To promote gender equality", "To strengthen the means of implementation and revitalize the Global Partnership for Sustainable Development", 3),
                Question(2, "Which UN agency is primarily responsible for coordinating international cooperation under SDG 17?", "UNESCO", "UNICEF", "UNDP", 3),
                Question(3, "What is the focus of SDG 17, Target 17.6?", "Reducing inequality", "Ensuring access to education", "Enhancing North-South cooperation", 1),
                Question(4, "Which of the following is a principle of effective development cooperation under SDG 17?", "Isolationism", "Transparency and accountability", "Unilateral decision-making", 2),
                Question(5, "What does the term 'ODA' stand for in the context of SDG 17?", "Overseas Development Assessment", "Official Development Assistance", "Operational Development Agreement", 2),
                Question(6, "In SDG 17, what is meant by the term 'technology transfer'?", "Returning technology to developed countries", "Sharing technology between countries", "Selling technology to the highest bidder", 2),
                Question(7, "Which aspect of SDG 17 addresses issues related to debt sustainability?", "Target 17.3", "Target 17.4", "Target 17.5", 3),
               Question(8, "What is the role of SDG 17 in addressing global trade challenges?", "Promoting protectionism", "Encouraging fair and equitable trade", "Restricting trade agreements", 2),
                Question(9, "Which international event in 2015 adopted the 2030 Agenda for Sustainable Development, including SDG 17?", "Rio+20 Summit", "Copenhagen Climate Summit", "UN General Assembly", 3),
                Question(10, "What is the significance of SDG 17 in the context of peace and security?", "It focuses on military alliances", "It emphasizes disarmament", "It recognizes the importance of partnerships in achieving peace and security", 3),
                Question(11, "How does SDG 17 contribute to global health?", "By providing healthcare services directly", "By supporting international cooperation for health", "By focusing only on local health issues", 2),
               
               Question(12, "Which SDG 17 target aims to enhance policy coherence for sustainable development?", "Target 17.14", "Target 17.15", "Target 17.16", 1),
                Question(13, "What is the primary objective of SDG 17, Target 17.17?", "Encouraging global partnerships", "Strengthening domestic resource mobilization", "Promoting sustainable tourism", 2),
                Question(14, "In the context of SDG 17, what is meant by 'South-South cooperation'?", "Cooperation among southern hemisphere countries", "Collaboration between developed and developing countries", "Collaboration among developing countries", 3),
                Question(15, "Which international organization plays a key role in promoting international trade under SDG 17?", "World Health Organization (WHO)", "World Trade Organization (WTO)", "World Bank", 2),
               Question(16, "What is the significance of SDG 17 in achieving environmental sustainability?", "It focuses on wildlife conservation", "It emphasizes the protection of natural resources", "It promotes global cooperation for environmental protection", 3),
               Question(17, "Which indicator measures the total government spending on SDG implementation under SDG 17?", "Indicator 17.15.1", "Indicator 17.16.1", "Indicator 17.17.1", 1),
                Question(18, "What is the purpose of the 'Global Partnership for Sustainable Development Data' under SDG 17?", "To promote open data sharing", "To collect data for academic research", "To restrict data access", 1),
                Question(19, "Which type of partnerships does SDG 17 emphasize for achieving its goals?", "Public-private partnerships", "Government-only partnerships", "Academic partnerships", 1),
                Question(20, "What is the role of SDG 17 in addressing climate change?", "It focuses on reducing carbon emissions", "It emphasizes the importance of international climate agreements", "It advocates for individual lifestyle changes", 2),
                Question(21, "Which international forum is associated with the review of SDG 17 progress?", "G7 Summit", "High-level Political Forum on Sustainable Development (HLPF)", "World Economic Forum (WEF)", 2),
    };

    Quiz quiz(quizArray, numQuestions);

    string player_name;
    string player_matric_no;
     
    cout << "Hey, no more wait! We are group matrix so excited to help you. Please enter your name: ";
    cin >> player_name;
    cout << "please use your matric no to be in the quiz! enter your matric number: ";
    cin >> player_matric_no;
 
     
    Player player(player_name);
 
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Start Quiz\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quiz.run();
                break;
            case 2:
                cout << "Thank you for playing this Quiz, and thanks to our lecturer Dr. Jamilah Mahmood. I am " << player.get_name() << "!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1 or 2.\n";
        }
    } while (choice != 2);

    return 0;
}
