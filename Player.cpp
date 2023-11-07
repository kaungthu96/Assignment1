/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kaung M Thu
Date: Nov 2023
Player.cpp implements the Player class.
*/

#include "Player.hpp"
#include <iostream>

/**
 * @post: Construct a new Player object
 */
Player::Player() : hand_(), score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {
}

/**
 * @post: Destroy the Player object
 */
Player::~Player() {
    delete actiondeck_;
    delete pointdeck_;
}

/**
 * @return the player's hand
 */
const Hand& Player::getHand() const {
    return hand_;
}

/**
 * @post: Set the player's hand
 * @param hand: a const reference to a hand object
 */
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const {
    return score_;
}

/**
 * @post: Set the player's score
 * @param score: an integer score
 */
void Player::setScore(const int& score) {
    score_ = score;
}

/**
 * @post: Play a given action card
 * @param card: an ActionCard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard&& card) {
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
}

/**
 * @post: Draw a point card and place it in the player's hand
 */
void Player::drawPointCard() {
    if (pointdeck_ && !hand_.isEmpty()) {
        hand_.addCard(pointdeck_->Draw());
    }
}

/**
 * @post: Play a point card from the player's hand and update the player's score
 */
void Player::playPointCard() {
    if (!hand_.isEmpty()) {
        int points = hand_.PlayCard();
        score_ += points;
    }
}

/**
 * @post: Set the opponent of the player
 * @param opponent: a pointer to a Player opponent
 */
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

/**
 * @return: a pointer to the player's opponent
 */
Player* Player::getOpponent() {
    return opponent_;
}

/**
 * @post: set the action deck of the player
 * @param actiondeck: A pointer to a deck holding Action cards
 */
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param pointdeck: A pointer to a deck holding Point cards
 */
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}
