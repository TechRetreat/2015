# Introduction
- Yu Chen Hou - [yuchen.io](http://yuchen.io)
- Jason Zukewich - [jzukewich.me](http://jzukewich.me/)
- Daniel Rampelt - [danielrampe.lt](https://danielrampe.lt/)
- Simon Fan - [https://github.com/xmfan](https://github.com/xmfan) 
- Dave Pagurek - [www.davepagurek.com](http://www.davepagurek.com/)
- Joey Pereira - [pereira.io](http://pereira.io/)

### Slack reminder
If you haven't yet joined our Slack, please do. We sent invitations to your application email, the link to the sign up will be in that email. If not, find a mentor and we'll get you on.

We will be keeping everyone up to date on the #software-learnathon channel. You can use Slack to ask for help/advice throughout the day.

### Challenge
We'll be writing AI bots on TechTanks, an arena-styled tank fighting game inspired by Robocode and Rtanque. Head over to http://techtanks.techretreat.ca/, sign up and activate your account. If you have any problems at any point, you can ask a mentor for help.

### Creating our first bot
Let's start by creating our first bot. Click the “Create a Tank” button from the home screen and pick a name and color for your bot. These settings can be changed at any time so don't worry about it too much. Lets head into the 'Code' section.

### Editor and replays
This is where you'll be spending most of your day, on the left we have our code editor, 'Tank Options' where you can change your color and name, 'Publish Code' and 'Logs', we'll get to those two later.

On the right we have our getting started page, the full documentation of TechTanks, and our game display, where your code will come to life.

Our AI will be written in Ruby. If you havent used Ruby before you might want to look at Codeacademy quickly (https://www.codecademy.com/tracks/ruby).



# Sample Bot
### TryRuby 'Hello World'

Before we begin, we'll go through a super simple 'Hello World' in Ruby using the TryRuby console (tryruby.org/levels/1/challenges/0)
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
Let's start by making a simple tank. Go to the 'Edit Code' tab and open 'Getting Started' on the right, then open the 'Bot Basics' section.
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
Before we begin making our bot, there are two TechTanks objects that you should understand, Points and Headings. Objects are things which hold changeable values. 

Let's start with Points (position), a point in TechTanks is basically an x, y location, where the top left corner of the screen is 0, 0. Create a point with RTanque::Point.new with x and y values, as well as an arena. Don't worry too much about the arena, its just so the point has a frame of reference, you should be fine using your tanks self.arena.

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
