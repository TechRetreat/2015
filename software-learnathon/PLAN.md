# Introduction

### Slack reminder
First, if you haven't yet joined our Slack, please do. You should all have invites, if not, find a mentor and we'll get you on.
We will be keeping everyone up to date on the #software-learnathon channel. You can use Slack to ask for help/advice throughout the day.

### Challenge
Today we'll be writing AI's for TechTanks, and fighting them to decide who takes home the prize. Head over to techtanks.techretreat.ca where we will be writing our bots.

To get started just sign up, head over to your email, and activate your account. If you have any problems ask a mentor for help.

### Create our first bot
Lets start by creating our first bot. Click the 'create a bot' button from then main screen and pick a name and color for your bot. These can be changed any time so dont worry about it for now. Lets head into the 'code' section.

### Editor and replays
This is where youll be spending most of your day, on the left we have our code editor, tank options where you can change your color and name, as well as published code and logs, we'll get to those two later.

On the right we have our getting started page, this has information to get started coding your bot, the full documentation of TechTanks, and our game display, where we fight our bots.

Our AI's today will be written in Ruby, if you havent used Ruby before you might want to look at Codeacademy quickly (www.codecademy.com/tracks/ruby).



# Sample Bot
### TryRuby 'Hello World'

Before we begin, we'll go through a super simple 'Hello World' in ruby using the TryRuby console (tryruby.org/levels/1/challenges/0)
In ruby, we print to console using 'puts', try running this command in the console
```ruby
puts 'Hello'
```

If blocks in ruby are written between a condition and an end
```ruby
if true
  puts ' World!'
end
```

You can also define your own methods and run them
```ruby
def ourPrint
  puts 'Our very own method!'
end

ourPrint
```

### Bot Structure
Lets start by making a simple tank, go to the TechTanks Edit tab and open Getting Started on the right, then open the Bot Basics section.
Our tank logic will go in the tick! method, which gets called every frame of the battle.

Here is where we can check whats going on on the battlefeild through self.sensors, and tell our bot what to do using self.command

### Running game/Logging
To test, we can copy our code from TryRuby in tick! and see what happens. Since we don't want to print every tick we'll only print if self.sensors.ticks equals 1.

```ruby
def tick!
  if self.sensors.ticks == 1
    puts 'Running'
  end
end
```

To fight your tank, click the play arrow on the top right. The logs will show up in the TechTanks console.

### Points and Headings
Before we begin making our bot, there are two TechTanks objects that you should understand a bit, Points and Headings. For those that dont know, objects are simply things things that hold values that can be changed. 

Let's start with Points, a point in TechTanks is basically an x, y location, where the top left corner of the screen is 0, 0. Create a point with RTanque::Point.new with x and y values, as well as an arena. Don't worry too much about the arena, its just so the point has a frame of reference, you should be fine using your tanks self.arena.

Most things have Point locations, like our tanks (mouse over self.sensors.position). 

There's a few things Points have build in, you can find them in the getting-started section, or the docs (mouse over each).

Directions in techtanks are held in Headings, basicaly just an angle, with some stuff to help us out, again you can look at the getting started section.



# Wrap up coding
### Save/publish code
When your tank is ready to fight, go to the editor and publish your code. Published code is the version of your tank that other people fight against when they make a new match.

At the end of the day, the version of your code that is published is the version that will be used in the competition.

If you're ever wondering what code is currently published, just go to the 'View Published Code' section.

### Docs
The docs are pretty self explanatory, you can also use the RTanque docs online, but we've changed a few things for TechTanks. The full list of changes is in the last section of our docs.

## Closing
Remember that we have mentors here, feel free to ask them for help any time.

If you find any bugs, or think of any features that would be cool or useful to have in TechTanks, slack it to Jason Zukewich and well try to fix/build it.

That's it, have fun!







