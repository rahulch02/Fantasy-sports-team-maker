# Fantasy Sports Team Maker

~~My first project/mini-project~~ :P

- This C++ program will print all possible teams that can be made from given player data. Such that the sum of the team's player value is 100 and I've also put conditions for minimum and maximum batsmen/bowlers/all-rounders.
It will also display captain and vice-captain for the teams. Captain: player with highest value, Vice-Captain: player with second-highest value

- The program can take input manually or you can make a text file and redirect stdin to that file using `<player_data.txt`. Stdout can be redirected similarly using `>output.txt`.
you have to write these commands in your console.

- For player condition, Change the conditions in `show_teams()`

_After running, The program will take 5-10mins to check all combinations and store them into the all_teams vector.
At this moment, console screen will be stuck showing All possible teams. Give it time and it'll start printing all the possible teams._

##### I have more plans for this program but atm, I'm planning to learn more languages and libraries and come back wiser to improve the features of this program.

Some features that I plan to add: 
* Sort the teams such that the team with highest median player value is at the top
* After sorting, limit the ouput to 50-100 teams so this program can actually assist people in making teams.

Also, I know the code is messy and fucked up but gimme some slack this was ya boi's first miniproject :D
I might improve it idk lezz see.
