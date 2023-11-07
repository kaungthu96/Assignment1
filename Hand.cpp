/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kaung M Thu
Date: Nov 2023
Hand.cpp Defines the Hand class.
*/
#include "Hand.hpp"
#include <iostream>
#include <stdexcept>

        /**
         * @post: Construct a new Hand object
         */
Hand::Hand() {

}

        /**
         * @post: Destroy the Hand object
         */
Hand::~Hand() {
    cards_.clear();
}

        /**
         * Copy Constructor
         * @param: other Hand object
         */
Hand::Hand(const Hand& other) :cards_ (other.cards_) {
 //copy the contents of the other Hand
}

        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
Hand& Hand::operator=(const Hand& other) {
    if(&other != this){
        cards_ = other.cards_;
        }
        return *this;
}

        /**
         * Move Constructor
         * @param: other Hand object
         */
Hand::Hand(Hand&& other) : cards_(other.cards_) {
    other.cards_ = cards_;
}

        /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
Hand& Hand::operator=(Hand&& other) {
    if(this!=&other) {
        std::swap(cards_, other.cards_);
    }
    return *this; 
}

        /**
         * @return Hand
         */
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
void Hand::addCard(PointCard&& card) {
    cards_.push_back(card);
}

        /**
         * @return true if hand is empty, false otherwise
         */
bool Hand::isEmpty() const {
    return cards_.empty();
}

        /**
         * @post: Reverse the hand
         */
void Hand::Reverse() {
    std::reverse(cards_.begin(), cards_.end());
}

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
int Hand::PlayCard() {
    if(isEmpty()) {
        throw std::runtime_error("Cannot play card - hand is empty");
    }
    int point = *cards_.front().getImageData();
    cards_.pop_front(); // remove the first (top) card in the deck
    return point;
}

