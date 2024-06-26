# Cricket-Simulator
Implemented in C++, cricket simulator is a console based game, in which a cricket match is simulated between 2 teams and results are stored in a file.
You have to make a simulator of cricket match. Make two teams of 11 players each. Each player will
have his name, runs scored, balls faced, balls bowled, runs given, wickets taken. [use 1D/2D/3D
arrays].
Your match simulation will be performed using excessive use of random function. The execution of
the simulation will be in the following order
• Match will be simulated for N number of overs. Value of N will be read from the
configuration.txt file. [use filing]
• Toss will be done and any team can win the toss and bat first. [random function]
• Player 1 and Player 2 of the batting team will appear on the score card. Player 1 will face the
first ball. Later on, the batsman facing the ball will be decided as follows: [setw()]
o Score 1,3,5 will mean other end batsman will face next ball.
o Over completed means other end batsman will face next ball.
• Bowler 1 will be the last player of Team B. Bowler 2 will be the second last player of team B
and so on. Last fiver players of Team B will be bowlers. Each bowler can bowl a maximum of
total_overs/5 overs (e.g. for a 20 over match, maximum overs bowled by a bowler would be
4).
• Ball will be bowled by pressing ENTER key. Each ball bowled will get a hit which will get some
score randomly (-1 – 6). If -1 comes, batsman is declared OUT. [Scoreboard changes will be
done by clearing the screen and then drawing again with new values. You can use
system(“clear”) function to clear the console and should have your own function to draw()
scoreboard again with new values which should be passed to the function.]
• All batsmen don’t have same probability of getting out, that is, a bowler (player number 6 to
11) will have 50% chance of getting out on each ball and 50% of getting any score from 0-6.
Similarly, a batsman (player number 1 to 5) will have 10% chance of getting out and 90%
chance of getting score 0-6 on each ball.

• There should be a function to find total score to be displayed on the scorecard which is also
displayed by a function. Total score is actually sum of scores of all players who batted.
Similarly, total dismissed is sum of all players who got out.
• If a batsman is DISMISSED/OUT, his score card will be displayed until ENTER is pressed again.
After that, main score card is displayed again. [You can stop output until a key is pressed by
using cin.get() function. And then clear the screen and then redraw Scoreboard]

• The innings of the team playing first will end if all overs are bowled or all players are dismissed.
In any case, full scorecard should be displayed showing full innings summary.
• There should be a special key to press during the program which will prompt user to enter the
over number to directly jump to; so that we can skip ENTER key for each ball and possibility
to jump to a particular over or the end of innings directly. To make more interesting, you can
introduce an optional short delay after each ball bowled so that you can see how match is
proceeding.
• Seconds innings will be executed same as before except that the target, remaining score,
remaining overs, required run rate is also included in the score card. You don’t need to display
first innings scoreboard when second innings is being played.

• When match is finished, user gets an option to show a short summary of the match, show first
innings, show second innings, save match data on file, load a previous match data. [Use files
to write and read match data, switch statement to display this menu]
Result
• Bowler taking highest wickets will be declared bowler of the match.
• Batsman scoring highest runs will be declared batsman of the match.
• Team winning will be shown as winner.
