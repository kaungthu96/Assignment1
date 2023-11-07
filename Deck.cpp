/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kaung M Thu
Date: Nov 2023
Deck.hpp defines the Deck class.
*/

#include "Deck.hpp"
        /**
         * @post: Construct a new Deck object
         */
template<typename CardType>
Deck<CardType>::Deck() {

}

        /**
         * @post: Destroy the Deck object 
         */
template <typename CardType>
Deck<CardType>::~Deck() {
    cards_.clear();
}

        /**
         * @post: Add a Card to the Deck
         * @param: const reference to CardType card
         */
template<typename CardType> 
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

        /**
         * @post: Draw a card from the deck
         * @pre: the deck is not empty
         * @return the right hand value of type CardType 
         */
template<typename CardType> 
CardType&& Deck<CardType>::Draw() {
    if (cards_.empty()) {
        throw std::runtime_error("Error: Attempted to draw card from an empty deck");
        } 
    CardType drawnCard = Deck.pop();
    return std::move(drawnCard);
}

        /**
         * @return if the deck is empty 
         */
template<typename CardType> 
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}  

        /**
         * @post: Shuffle the deck 
         * Create a random number generator using std::mt19937 with seed 2028358904, 
         * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.  
         * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
         * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
         */
template<typename CardType> 
void Deck<CardType>::Shuffle() {
   // Create a random number generator using std::mt19937 with a fixed seed
    std::mt19937 rng(2028358904)
    //Shuffle the deck using the random number generator 
    std::shuffle(std::begin(cards_), std::end(cards_), rng);
}

        /**
         * @return the size of the deck 
         */
template<typename CardType> 
int Deck<CardType>::getSize() const {
    return static_cast<int>(cards_.size());
}
    
        /**
         * @return the vector of cards in the deck 
         */
template<typename CardType> 
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}