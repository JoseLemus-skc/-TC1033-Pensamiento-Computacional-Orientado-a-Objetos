#include <iostream>
#include <string>

class BTrack{
    private:
        std::string trackName;
        int cuePosition;
        float trackLength;
        float countinLength;
        float totalLength;
        std::string sourceDevice;
        std::string operatorName;

    public:
        // Constructores
        BTrack(): trackName("n/a"), cuePosition(0), trackLength(0.0), countinLength(0.0), totalLength(0.0), sourceDevice("n/a"), operatorName("n/a"){};
        BTrack(std::string tName, int cue, float trkLen, float cntLen, float totLen, std::string source, std::string optr): trackName(tName), cuePosition(cue), trackLength(trkLen), countinLength(cntLen), totalLength(totLen), sourceDevice(source), operatorName(optr){};
       
        // Setters
        void set_trackName();
        void set_cuePosition();
        void set_trackLength();
        void set_countinLength();
        void set_totalLength();
        void set_sourceDevice();
        void set_operatorName();

        // Getters
        void get_trackName();
        void get_cuePosition();
        void get_trackLength();
        void get_countinLength();
        void get_totalLength();
        void get_sourceDevice();
        void get_operatorName();
};

