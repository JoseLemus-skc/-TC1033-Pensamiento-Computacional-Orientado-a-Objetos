#include <iostream>
#include <string>

class Inst{
    private:
        int lineNumber;
        std::string playerName;
        bool microphone;
        bool directLine;
        bool diBox;
        bool preAmp;
    public:
        // Constructores
        Inst(): lineNumber(0), playerName("n/a"), microphone(false), directLine(false), diBox(false), preAmp(false){};
        Inst(int line, std::string name, bool micro, bool dLine, bool di, bool amp): lineNumber(line), playerName(name), microphone(micro), directLine(dLine), diBox(di), preAmp(amp){};
        
        // Setters
        void set_lineNumber();
        void set_playerName();
        void set_microphone();
        void set_directLine();
        void set_diBox();
        void set_preAmp();

        // Getters
        void get_lineNumber();
        void get_playerName();
        void get_microphone();
        void get_directLine();
        void get_diBox();
        void get_preAmp();
};