/**
 * Author: Suseela Chinniah
 * Date: Nov 9th, 2020
 * 
 * Declares the methods and attributes of keyboard class
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_INVENTORY 'i'
#define KEY_USE 'u'

class Keyboard {
  public:
    Keyboard();
    ~Keyboard();
    bool up(char input);
    bool down(char input);
    bool left(char input);
    bool right(char input);
    bool inventory(char input);
    bool use(char input);
};

#endif
