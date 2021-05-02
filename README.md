# Mastermind

<p align="center">
  <img src="/resources/readme/mastermind_legend.jpg">
  <p align="center">Illustration 1 - Layout of the Mastermind game window.</p>
</p>

This is a Mastermind game with changed rules so that all possible combinations are calculated and the scoring is adjusted so it doesn't punish the correct lines of play. To make the scoring less based on luck and more on skill and correct reasoning, the amount of points that can be won is only reduced if there is one possible combination remaining, and the player makes the wrong guess. 

This scoring allows players who played correctly but who didn't get lucky because they encountered the worst-case scenario for their guesses to still get the full amount of points. If the player gets lucky, and guesses before the number of possible combinations are reduced to one, he is still awarded the full amount of points. Points that can be won are only reduced if the correct guess can be made with 100% certainty because only one possible combination remains, and the player fails to make the guess.

## Standard scoring in Mastermind

In a game of Mastermind with 6 signs and 4 positions, there are 1296 possible combinations for the correct guess initially. By guessing and receiving feedback for the guesses, the number of possible combinations can be reduced down to one. At that point, it is possible to guess the combination correctly with 100% certainty if the person reasons correctly based on available information. If the Knuth method is used ([Knuth - The computer as mastermind](https://www.cs.uni.edu/~wallingf/teaching/cs3530/resources/knuth-mastermind.pdf)) the worst-case scenario is that a person guesses correctly in five steps. If the player is lucky, he can of course make the correct guess at any point, well before he has reduced the number of possible remaining combinations to just one combination. 

Current scoring for the mastermind game in "Slagalica" quiz in Serbia ([Scoring rules](https://www.rts.rs/page/rts/sr/rtspredstavlja/Slagalica/story/3054/pravila-i-prijave/3622033/pravila-su-pravila.html)) is based on the number of tries the player takes to guess the correct combination:
* 20 points if the player guesses correctly on the first or second try
* 15 points if the player guesses correctly on the third or fourth try
* 10 points if the player guesses correctly on the fifth or sixth try.

This means that the player will often get the full 20 points only if he gets lucky and guesses correctly in the first 2 tries. The only case where there is only one possible combination remaining after the first try is if the first guess consists of only two signs that appear two times each in the combination, and the indicators show that all the signs are not at the correct places (Illustration 2). The chance of this happening is 1/1296 and it is the same chance as guessing the correct combination outright on the first try.

<p align="center">
  <img src="/resources/readme/guess_certain_first_try.jpg">
  <p align="center">Illustration 2 - Only one possible combination remains after the first try.</p>
</p>

## Problem with standard scoring in Mastermind

The problem with the current scoring is that it punishes players who play correctly but don't get lucky to make the correct guess early. In the case that the player uses the Knuth method that guarantees the correct guess in 5 tries or less if the guess happens on the fifth try, he would get the minimum amount of points (Illustration 3). This is why standard scoring punishes correct play and rewards luck.

<p align="center">
  <img src="/resources/readme/knuth_method_worst_case.jpg">
  <p align="center">Illustration 3 - Unlucky scenario when the Knuth method is used.</p>
</p>

## Proposed alternative scoring

It is fine for the player to get the full amount of points if he gets lucky and guesses the correct combination before he has reduced the number of possible combinations to one. These situations will happen because there is always a chance to guess correctly and the player should not be punished for being lucky. 

But if the player reduces the number of possible combinations down to one, and he fails to make a correct guess on the next try, then the number of points that he can win should be reduced. 
This point reduction is done because the player failed to reason correctly from the information that he has available.

Alternative scoring could start at 15 points. Points could be reduced in the following way for each wrong guess after the number of possible combinations is reduced to 1:
* 1st missed certain guess = -5 points
* 2nd missed certain guess = -4 points
* 3rd missed certain guess = -3 points
* 4th missed certain guess = -2 points.

The maximum possible reduction would occur if the guess is certain on the second try, but the player fails to make the correct guess every step of the way until the last try (Illustration 4). In this case, he would end up winning only 1 point, because the points were reduced after the 2nd, 3rd, 4th, and 5th wrong try.

<p align="center">
  <img src="/resources/readme/worst_play.jpg">
  <p align="center">Illustration 4 - Worst line of play that ends in a win.</p>
</p>

This way the player can still get the maximum amount of points if he plays correctly but gets unlucky and reduces the number of possible combinations down to 1 on the 4th or 5th try and makes the correct guess on the next try (Illustration 5). 

<p align="center">
  <img src="/resources/readme/guess_worst_case.jpg">
  <p align="center">Illustration 5 - Unlucky scenario when the Knuth method is not used. </p>
</p>


