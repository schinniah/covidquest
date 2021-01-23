#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>

class Timer {
    private: 
        static  Timer* sInstance;
        unsigned int mStartTicks;
        unsigned int mElapsedTicks;
        float mDeltaTime;
        float mTimeScale;

    public:

        Timer();
        ~Timer();

        static Timer *instance();
        static void release();
        void reset();
        float getDeltaTime();
        void setTimeScale(float time);
        float getTimeScale();
        void update();        
};

#endif