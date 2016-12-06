# 3220_final
3220 Final Project - Ian Naeger, Christopher Smith

** Project proposal **
We intend to build a casino like gaming experience, one which will contain TWO mini games that the user can play

we want to allow the user to create an account, save their high scores, to be able to compare them to other users

there will also be an option to play as a guest (base class) which allows the user to play the games without tracking progress

playing as a user account (inheritance of the base class) will give access to the leaderboard and other functionality

there will also be cheat codes, when entered will have several options, your scores could be scaled, offset if youd wish, there will also be options to blatantly ignore some functionality of some games (dynamic binding) to make them much easiet to play!

cheat codes will only be available to the two creator accounts (another inherited class) and namely, chris and ian, who will
have passwords (most likely defined in the header files)

users will be able to delete their accounts (and memory must be freed correctly here)

*POSSIBLE* hardware implementation - have one of the games be on a physical board for the user to play (simon says or something that includes LEDs and buttons)

main functionality will be the points system, which needs to be kept track of and updated with each game played


**Notes on the code**
>code still contains severals portions that are commented out, these are mainly in place to ensure we can easily debug (visually in this case) should our functions stop working
>

**How to use program**
>To compile our program, simply be in the main directory and run the "make" command, this will compile all source files and create the executable named "./final"
>to run this executable, simply run the "./final" command
>NO command line arguments will be needed, and none will be understood by our program
>Our program then walks the user step by step, asking questions along the way to gather its corresponding inputs and give the correct outputs

**Known issues / Bugs**
>the simon says game is not working quite right at the moment, we need to ensure that it will terminate as soon as the user enters an incorrect number
>
