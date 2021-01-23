/**
 * @brief Timer class
 * @details Class file for Timer object
 * 
 * @author Ibai Seco
 */

/*
-----------------------------------------------------
 INCLUDES
-----------------------------------------------------
*/
#include "Timer.h"

Timer *Timer::sInstance = NULL;

/**
 * @brief Construct a new Timer:: Timer object
 * @details This is a constructor of a new Timer object
 */
Timer::Timer() {
    reset();
    mTimeScale = 1.0f;
}

/**
 * @brief Destroy the Timer:: Timer object
 * @details This is a destructor of the Timer object
 */
Timer::~Timer() {}

/**
 * @brief Instancce
 * @details Instance for the timer
 * 
 * @return Timer* 
 */
Timer *Timer::instance() {
    if (sInstance == NULL)
        sInstance = new Timer();

    return sInstance;
}

/**
 * @brief Release
 * @details Instance is NULL
 */
void Timer::release() {
    delete sInstance;
    sInstance = NULL;
}

/**
 * @brief Reset
 * @details Reset the timer to 0
 */
void Timer::reset() {
    mStartTicks = SDL_GetTicks();
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;
}

/**
 * @brief Getter function
 * @details Get delta time
 * 
 * @return float 
 */
float Timer::getDeltaTime() {
    return mDeltaTime;
}

/**
 * @brief Setter function
 * @details Set the time scale using the input time
 * 
 * @param time 
 */
void Timer::setTimeScale(float time) {
    mTimeScale = time;
}

/**
 * @brief Getter function
 * @details Get time scale
 * 
 * @return float 
 */
float Timer::getTimeScale() {
    return mTimeScale;
}

/**
 * @brief Update
 * @details Update the timer
 */
void Timer::update() {
    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * 0.001f;
}
