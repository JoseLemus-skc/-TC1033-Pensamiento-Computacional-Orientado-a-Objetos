#include <iostream>
#include <string>

class Micr{
    private:
        std::string receiverRack;
        int inputNumber;
        std::string microphoneType;
        std::string microphoneUse;
        int battery;
        bool live;
        std::string userName;
    public:
        // Constructores
        Micr(): receiverRack("n/a"), inputNumber(0), microphoneType("n/a"), microphoneUse("n/a"), battery(0), live(false){};
        Micr(std::string rack, int input, std::string type, std::string use, int btry, bool micOn): receiverRack(rack), inputNumber(input), microphoneType(type), microphoneUse(use), battery(btry), live(micOn){};

        // Setters
        void set_receiverRack();
        void set_inputNumber();
        void set_microphoneType();
        void set_microphoneUse();
        void set_battery();
        void set_live();
        void set_userName();

        // Getters
        void get_receiverRack();
        void get_inputNumber();
        void get_microphoneType();
        void get_microphoneUse();
        void get_battery();
        void get_live();
        void get_userName();
};