# Mastermind
This is a Mastermind game with changed rules so that all possible combinations are calculated and the scoring is adjusted so it doesn't punish the correct lines of play. To make the scoring less based on luck and more on skill and correct reasoning, the ammount of points that can be won is only reduced if there is one possible combination remaining, and the player makes the wrong guess. 

This scoring allows players who played correctly but who didn't get lucky because they encountered the worst case scenario for their guesses to still get the full ammount of points. If the player gets lucky, and guesses before the number of possible combinations is reduced to one, he is still awarded the full ammount of points. Points that can be won are only reduced if the correct guess can be made with 100% certanty because only one possible combination remains, and the player fails to make the guess.

# Standard scoring in Mastermind

In a game of Mastermind with 6 signs and 4 positions, there are 1296 possible combinations for the correct guess initially. By guessing and receiving feedback for the guesses, number of possible combinations can be reduced down to one. At that point it is possible to guess the combination correctly with 100% certanty if the person reasons correctly based on available information. If the Knuth method is used ([Knuth - The computer as mastermind](https://www.cs.uni.edu/~wallingf/teaching/cs3530/resources/knuth-mastermind.pdf)) the worst case scenario is that a person guesses correctly in five steps. If the player is lucky, he can ofcourse make the correct guess at any point, well before he has reduced the number of possible remaining combinations to just one combination. 

Current scoring for the mastermind game in "Slagalica" quiz in Serbia ([Scoring rules](https://www.rts.rs/page/rts/sr/rtspredstavlja/Slagalica/story/3054/pravila-i-prijave/3622033/pravila-su-pravila.html)) is based on the number of tries the player takes to guess the correct combination:
* 20 points if the player guesses correctly on the first or second try
* 15 points if the player guesses correctly on the third or fourth try
* 10 points if the player guesses correctly on the fifth or sixth try.

This means that the player will often get the full 20 points only if he gets lucky and guesses correctly in the first 2 tries. Only case where there is only one possible combination remaining after the first try is if the first guess consists of only two signs that appear two times each in the combination, and the indicators show that all the signs are not at the correct places (Ilustration 1). Chance of this happening is 1/1296 and it is the same chance as guessing the correct combination outright on the first try.

<p align="center">
  <img src="/resources/readme/guess_certain_first_try.jpg">
  <p align="center">Ilustration 1 - Only one possible combination remaining after the first try</p>
</p>

# Problem with standard scoring in Mastermind


