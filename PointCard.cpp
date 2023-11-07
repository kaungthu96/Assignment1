/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name : Kaung M Thu
Date : Nov 2023
PointCard.hpp defines the PointCard class and inherits from the Card Class.
*/

#include "PointCard.hpp"

        /**
         * @post: Construct a new Point Card object
         */
PointCard::PointCard() : Card() { } // Constructor 

        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
bool PointCard::isPlayable() {
    if (getDrawn() == false) {
        return false;
    }
    if (stoi(getInstruction()) > 99 || stoi(getInstruction()) < 1) {
        return false;
    }
    return true;
}

        /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void PointCard::Print() const {
    std::cout 
    << "Type: " << getType() << "\n"
    << "Points: " << getInstruction() << "\n"
    << "Card: " << "\n";

    if (getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }
    else {
        std::cout << getImageData();
    }
}
