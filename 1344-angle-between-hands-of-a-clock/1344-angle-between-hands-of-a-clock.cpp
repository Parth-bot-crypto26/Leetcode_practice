class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrAngle = (hour%12)*30.0 + minutes*0.5;
        double minAngle = minutes*6.0;
        double angle = abs(hrAngle - minAngle);
        if(angle > 180.0){
            angle = 360.0-angle;
        }
        return angle;
    }
};