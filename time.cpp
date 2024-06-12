#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void validate(int h, int m, int s) {
        if (h < 0 || h >= 24 || m < 0 || m >= 60 || s < 0 || s >= 60) {
            throw invalid_argument("Invalid time values.");
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}


    Time(int h, int m, int s) {
        validate(h, m, s);
        hours = h;
        minutes = m;
        seconds = s;
    }

    
    Time(int totalSeconds) {
        hours = (totalSeconds / 3600) % 24;
        minutes = (totalSeconds / 60) % 60;
        seconds = totalSeconds % 60;
    }

    
    void printTime() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }


    int difference(const Time& other) const {
        int thisTotalSeconds = hours * 3600 + minutes * 60 + seconds;
        int otherTotalSeconds = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return abs(thisTotalSeconds - otherTotalSeconds);
    }

    int getHours() const { return hours; }

    int getMinutes() const { return minutes; }

    int getSeconds() const { return seconds; }
};

int main() {
    try {
        Time time1(12, 30, 45);
        Time time2(14, 45, 15);

        cout << "Time 1: ";
        time1.printTime();

        cout << "Time 2: ";
        time2.printTime();

        int diff = time1.difference(time2);
        cout << "Difference in seconds: " << diff << " seconds" << endl;

        
        int totalSeconds = 3723;
        Time time3(totalSeconds);

        cout << "Time created from " << totalSeconds << " seconds: ";
        time3.printTime();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
