# Overview
### Introduction
- Remind people of slack and how were going to be using it (Note: we need to plan how we are going to use it effectively)
- Get everyone signed up and verified on TechTanks
- Have everyone start their first bot
- Show editor, tank-options, getting-started, and docs

### Sample Bot
- Do 'Hello World' in TryRuby
- Bot structure
- Demonstrate running game with TryRuby code
- Show Logging/console though 'Hello World' (Note: we need to figure out where console is going)
 (Something like if self.sensors.ticks == 0 puts, so we show an if block too, or put it in a function (maybe incrementally do all 3))
- Points/Headings

### Check whether kids want more demonstration
- Movement
- Enemies
- Shooting
- Sample
- Demonstrate failed code in console

### Wrap up coding
- Show how to save/publish code
- Show how docs are set up

### Closing
- Remind people to ask mentors for help
- Give one of our slacks to report bugs/feature requests to
- Reminder to have fun


# Detailed Plan

## Introduction
// Yu Chen

Good morning everyone, how has TR been going so far etc.
Everyone from learnathon? We prepped something really cool for you guys and we think you'll love it. Who here knows ruby? dont worry
Okay lets get strated

### Slack reminder
// Yu Chen

First, if you haven't yet joined our Slack (show slack), please do. You should all have invites, if not, come find me after and we'll get you on.
We will be keeping everyone up to date on the Software-Learnathon (show screen) channel. You can use slack to ask for help/advice throughout the day.

### Get everyone on the site
// Yu Chen
Now for the challenge, today we'll be writing AI's for TechTanks, and fighting them to decide whoo takes home the prize. Head over to (show new tab) techtanks.techretreat.ca where we will be writing our bots.

To get started just sign up (demonstrate), head over to your email, and activate your account. Hands up when your'e ready to start your tank

The goal of TechTanks is to destroy other bots, and survive as long as possible.

Bots start at random positions, shoot other bots to damage them, collisions damage both bots equally.

Your score is calculated as percent of total time survived + ending health + percent of bots killed

(wait for hands) Alright is everyone good to go? (if any problems, get a mentor helping that group)

### Create our first bot
// Jason

Alright, we're all in, lets start by creating our first bot. Click the 'create a bot' button (demonstrate) Then pick a name and color for your bot (demonstrate). These can be changed any time so dont worry about it for now. Lets head into the 'code' section (click code)

### Show editor and tab functions
// Jason

This is where youll be spending most of your day, on the left we have our code editor, tank options where you can change your color and name, as well as published code and logs, we'll get to those two later. (open first two tabs as you mention them, mouse over other two)

On the right we have our getting started page with all the stuff ill be going over now, the full documentation of TechTanks, and our game display, where we fight our bots (mouse over), once we have something to fight well show you how this works. (open each in turn and mouse over title)

(go back to editor and getting started tabs)

Our AI's today will be written in Ruby, if you havent used Ruby before you might want to look at Codeacademy quickly. The link is in the getting-started section. (mouse over link)




## TryRuby 'Hello World'
// Daniel

(http://tryruby.org/levels/1/challenges/0)

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

## Sample Bot
### Bot Structure
// Jason

Lets start by making a starter tank (go back to main tab of techtanks.techretreat.ca and open bot basics section)
Our tank logic will go in the tick! method, which gets called every frame of the battle.

Here is where we can check whats going on on the battlefeild through self.sensors, and tell our bot what to do using self.command

### Running game/Logging
// Jason

For example we can copy our ruby code from TryRuby in def and see what happens. Since we don't want to print every tick we'll only print if self.sensors.ticks equals 0.

```ruby
if self.sensors.ticks == 1
  puts 'Running'
end
```
(and run)

### Points and Headings (Also introduce to objects in general)
// Jason

Before we begin making our bot, there are two TechTanks objects that you should understand a bit, Points and Headings. For those that dont know, objects are simply things things that hold values that can be changed.

Let's start with Points (mouse to points in getting-started), a point in TechTanks is basically an x, y location, where the top left corner of the screen is 0, 0. Create a point with Point.new (Check if RTanque:: is needed) with x and y values, as well as an arena. Don't worry too much about the arena, its just so the point has a frame of reference, you should be fine using your tanks self.arena. (mouse over function parts as theyre called)

Most things have Point locations, like our tanks (mouse over self.sensors.position).

There's a few things Points have build in, you can find them in the getting-started section, or the docs (mouse over each).

Directions in techtanks are held in Headings, basicaly just an angle, with some stuff to help us out, again you can look at the getting started section.

## Wrap up coding
### Save/publish code
// Yu Chen

So lets say im ready to fight my tank, I can go to the editor and save my code, then I can publish it so other people can fight against my code.

If you're ever wondering what code is currently puslished for your tank, just go to the 'published code' section (go there)

### Show how docs are set up
// Yu Chen

Last quick note, the docs are pretty self explanatory, you can also use the rtanque docs online, but we've changed a few things for TechTanks

The full list of changes is in the last section (Note: We should do that)

## Closing
// Jason

Before everyone goes off, remember that we have mentors here to help you guys out, feel free to ask them for help any time.

Also if you guys find any bugs, or think of any features that would be cool or useful to have, slack it to Jason Zukewich and well try to fix or build it

That's it for now, have fun guys!

We've looked through your responses from the survey and a lot of you guys are interested in doing stuff on your own, so we'll let you get right to it now. If you want us to talk a bit more about AI and TechTank, come to us.







