# Introduction

### Slack reminder
If you haven't yet joined our Slack, please do. We sent invitations to your application email, the link to the sign up will be in that email. If not, find a mentor and we'll get you on.

We will be keeping everyone up to date on the #software-learnathon channel. You can use Slack to ask for help/advice throughout the day.

### Challenge
We'll be writing AI bots in TechTanks, an arena-styled tank fighting game inspired by Robocode and Rtanque. Head over to techtanks.techretreat.ca, sign up and activate your account. If you have any problems at any point, you can ask a mentor for help.

###Gameplay
The goal of TechTanks is to destroy other bots, and survive as long as possible.

Bots start at random positions, shoot other bots to damage them, collisions damage both bots equally.

Your score is calculated as percent of total time survived + ending health + percent of bots killed

### Creating our first bot
Let's start by creating our first bot. Click the “Create a Tank” button from the home screen and pick a name and color for your bot. These settings can be changed at any time so don't worry about it too much. Lets head into the 'Code' section.

### Editor and replays
This is where you'll be spending most of your day, on the left we have our code editor, 'Tank Options' where you can change your color and name, 'Publish Code' and 'Logs', we'll get to those two later.

On the right we have our getting started page, the full documentation of TechTanks, and our game display, where your code will come to life.

Our AI will be written in Ruby. If you havent used Ruby before you might want to look at Codeacademy quickly (https://www.codecademy.com/tracks/ruby).



## TryRuby 'Hello World'
Before we begin, we'll go over some of the basics of ruby.  You can follow along at tryruby.org

In ruby, we print to console using `puts`. Like most languages, any text you want to use must be in quotations
```ruby
puts "Hello, World!"
```

That works, but it's not too useful yet. We probably don't want to greet the whole world every time, so this is when we would use variables:
```ruby
name = "Daniel"
puts "Hello, " + name + "!"
```
This is how we add text together.

In Ruby you don't have to specify what type of data a variable is.
```ruby
x = "hello"
puts x

x = 10
puts x
```

Let's try some math:
```ruby
result = 5 * 5
puts "5 x 5 = " + result
```

Now let's say you wanted to find any number multiplied by five. You probably don't want to change the number each time, this is where we use methods. A method or function is a reusable block of code. You can give values to methods and have them send back results.
```ruby
def five_times(x)
  result = 5 * x
  return "5 x " + x + " = " + result
end

puts five_times(5)
puts five_times(7)
puts five_times(31)
```

If your tank needs to make decisions, you can use an `if` statement. If statements in ruby are written between a condition and an end
```ruby
if false
  five_times(5)
end
```
The condition should evaluate to either true or false

(Examples: `true`, `3 == 3`, `5 < 10`, `15 < 10`, `8 >= 7`, `"test" == "test"`, `3 < 5 && true`, `false || true`)

In our `five_times` method if we didn't want people to use larger numbers we can send back a message
```ruby
def five_times(x)
  if x > 100
    return "Number is too big"
  else
    result = 5 * x
    return "5 x " + x + " = " + result
  end
end
```

Next we have loops. In ruby you can use for and while loops similar to other languages:
```ruby
for x in [0, 1, 2, 3, 4, 5]
  puts five_times(x)
end

x = 0
while x <= 5
  puts five_times(x)
  x += 1
end
```
This will print the numbers from 0 to 5 multiplied by 5

But you can also use a different type of loop in ruby, anything that can be looped through has an `each` method
```ruby
[0, 1, 2, 3, 4, 5].each do |x|
  puts five_times(x)
end
```


# Sample Bot
### Bot Structure
Let's start by making a simple tank. Go to techtanks.techretreat.ca 'Edit Code' tab and open 'Getting Started' on the right, then open the 'Bot Basics' section.
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
