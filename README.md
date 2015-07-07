# Monty_Hall_Simulator
Simulates the monty hall problem and reports the statistics

Inspired by /r/dailyprogrammer
https://www.reddit.com/r/dailyprogrammer/comments/1qdw40/111113_challenge_141_easy_monty_hall_simulation/

I vaguely understood the Monty Hall problem prior to building this. I read some things and watched videos but they did not help as much as I would have liked. Getting my hands dirty with the problem was immensely helpful in understanding the paradox.

# Strategy #1: Staying
You will always have a 1/$doors chance to pick the car. Since you will not change your decision based on what Monty does. Your total chance is therefore 1/$doors.

# Strategy #2: Switching
You will pick a door, Monty does his thing, and you have a branching path a) If you picked the car door, then you will switch away and, and b) If you picked a goat door, then switching away will give you the car. These branching paths are based on the probability of your original choice.
#### Choice a)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You have 1/$doors ways to pick the car door, and therefore will always fail because you switch to the remaining goat door.
#### Choice b)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You have (1-1/$doors) ways to pick a goat, and therefore will always win because you switch to the remaining car door.

