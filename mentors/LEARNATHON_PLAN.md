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
<Yu Chen>
Good morning everyone, how has TR been going so far etc.

Okay lets get strated

### Slack reminder
<Yu Chen>
First, if you haven't yet joined our Slack (show slack), please do. You should all have invites, if not, come find me after and we'll get you on.
We will be keeping everyone up to date on the Software-Learnathon (show screen) channel. You can use slack to ask for help/advice throughout the day.

### Get everyone on the site
<Yu Chen>
Now for the challenge, today we'll be writing AI's for TechTanks, and fighting them to decide whoo takes home the prize. Head over to (show new tab) techtanks.techretreat.ca where we will be writing our bots.

To get started just sign up (demonstrate), head over to your email, and activate your account. Hands up when your'e ready to start your tank

The goal of TechTanks is to destroy other bots, and survive as long as possible.

Bots start at random positions, shoot other bots to damage them, collisions damage both bots equally.

Your score is calculated as percent of total time survived + ending health + percent of bots killed

(wait for hands) Alright is everyone good to go? (if any problems, get a mentor helping that group)

### Create our first bot
<Jason>
Alright, we're all in, lets start by creating our first bot. Click the 'create a bot' button (demonstrate) Then pick a name and color for your bot (demonstrate). These can be changed any time so dont worry about it for now. Lets head into the 'code' section (click code)

### Show editor and tab functions
<Jason>
This is where youll be spending most of your day, on the left we have our code editor, tank options where you can change your color and name, as well as published code and logs, we'll get to those two later. (open first two tabs as you mention them, mouse over other two)

On the right we have our getting started page with all the stuff ill be going over now, the full documentation of TechTanks, and our game display, where we fight our bots (mouse over), once we have something to fight well show you how this works. (open each in turn and mouse over title)

(go back to editor and getting started tabs)

Our AI's today will be written in Ruby, if you havent used Ruby before you might want to look at Codeacademy quickly. The link is in the getting-started section. (mouse over link)




## Sample Bot
### TryRuby 'Hello World'
<Daniel EXPAND STUFF ON RUBY>
(http://tryruby.org/levels/1/challenges/0)

Before we begin, we'll go through a super simple 'Hello World' in ruby using the TryRuby console (mouse over link and enter) 
In ruby, we print to console using 'puts'
```ruby
puts 'Hello'
```
(and run)

If blocks in ruby are written between a condition and an end
```ruby
if true
  puts ' World!'
end
```

You can also define your own methods and run them
```ruby
def ourPrint
  puts 'Our very own method'
end

ourPrint
```

If you want to try out Ruby in console the link is TryRuby in the getting-started section

### Bot Structure
<Jason>
Lets start by making a starter tank (go back to main tab and open bot basics section)
Our tank logic will go in the tick! method, which gets called every frame of the battle.

Here is where we can check whats going on on the battlefeild through self.sensors, and tell our bot what to do using self.command

### Running game/Logging
<Jason>
For example we can copy our ruby code from TryRuby in def and see what happens. Since we don't want to print every tick we'll only print if self.sensors.ticks equals 0.

```ruby
if self.sensors.ticks == 1
  puts 'Running'
end
```
(and run)

### Points and Headings (Also introduce to objects in general)
<Jason>
Before we begin making our bot, there are two TechTanks objects that you should understand a bit, Points and Headings. For those that dont know, objects are simply things things that hold values that can be changed. 

Let's start with Points (mouse to points in getting-started), a point in TechTanks is basically an x, y location, where the top left corner of the screen is 0, 0. Create a point with Point.new (Check if RTanque:: is needed) with x and y values, as well as an arena. Don't worry too much about the arena, its just so the point has a frame of reference, you should be fine using your tanks self.arena. (mouse over function parts as theyre called)

Most things have Point locations, like our tanks (mouse over self.sensors.position). 

There's a few things Points have build in, you can find them in the getting-started section, or the docs (mouse over each).

Directions in techtanks are held in Headings, basicaly just an angle, with some stuff to help us out, again you can look at the getting started section.

## Wrap up coding
### Save/publish code
<Yu Chen>
So lets say im ready to fight my tank, I can go to the editor and save my code, then I can publish it so other people can fight against my code.

If you're ever wondering what code is currently puslished for your tank, just go to the 'published code' section (go there)

### Show how docs are set up
<Yu Chen>
Last quick note, the docs are pretty self explanatory, you can also use the rtanque docs online, but we've changed a few things for TechTanks

The full list of changes is in the last section (Note: We should do that)

## Closing
<Jason>
Before everyone goes off, remember that we have mentors here to help you guys out, feel free to ask them for help any time.

Also if you guys find any bugs, or think of any features that would be cool or useful to have, slack it to Jason Zukewich and well try to fix or build it

That's it for now, have fun guys!

We've looked through your responses from the survey and a lot of you guys are interested in doing stuff on your own, so we'll let you get right to it now. If you want us to talk a bit more about AI and TechTank, come to us.







