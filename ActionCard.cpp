/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Kaung M Thu
Date Nov 2023
ActionCard.hpp defines the ActionCard class and inherits from the Card Class.
*/

#include "ActionCard.hpp"
#include <iostream>

        /**
         * @post: Construct a new Action Card object
        */
ActionCard::ActionCard() {
    setType( ACTION_CARD); //Default constructor 
}

        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
bool ActionCard::isPlayable() {
    if (getDrawn() == false) {
        return false;
    }
    if (getInstruction() == "SWAP HAND WITH OPPONENT" || getInstruction() == "REVERSE HAND") {
        return true;
    }
    std::regex pattern(R"((?:DRAW|PLAY)\s([1-9]\d{0,1})\sCARD\(S\))");
    if (!std::regex_match(getInstruction(), pattern)) {
        return false;
    }
    return true;
}

        /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void ActionCard::Print() const {
    std::cout 
    << "Type: " << getType() << "\n"
    << "Instruction: " << getInstruction() << "\n"
    << "Card: " << "\n";

    if (getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }
    else {
        std::cout << getImageData();
    }
}