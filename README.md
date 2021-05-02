# mastermind
Mastermind game with changed rules so that all possible combinations are calculated and points are adjusted accordingly.

# Problem with standard scoring in Mastermind

In a game of Mastermind with 6 signs and 4 positions, there are 1296 possible combinations for the correct guess initially. By guessing and receiving feedback for the guesses, number of possible combinations can be reduced down to one. At that point it is possible to guess the combination correctly with 100% certanty if the person reasons correctly from the available information. In the worst case scenario, person can guess the combination in 5 steps if the Knuth method is used ([Knuth - The computer as mastermind](https://www.cs.uni.edu/~wallingf/teaching/cs3530/resources/knuth-mastermind.pdf)). If the player is lucky, he can ofcourse make the correct guess at any point, well before he has reduced the number of possible remaining combinations to just 1 combinations. 

Current scoring for the mastermind game in "Slagalica" quiz in Serbia ([Scoring rules](https://www.rts.rs/page/rts/sr/rtspredstavlja/Slagalica/story/3054/pravila-i-prijave/3622033/pravila-su-pravila.html)) is based on the number of tries the player takes to guess the correct combination:
* 20 points if the player guesses correctly on the first two tries
* 15 points if the player guesses correctly on the third or fourth try
* 10 points if the player guesses correctly on the fifth or sixth try.

This means that the player will often get the full 20 points only if he gets lucky and guesses correctly in the first 2 tries. Only case where there is only one possible combination remaining after the first try is if the first guess consists of only two signs who appear two times each in the combination, and the indicators show that all the signs are not at the correct places (Ilustration 1). Chance of this happening is 1/1296 and it is the same chance as guessing the correct combination outright on the first try.


