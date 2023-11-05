
# Build and Run The Skydio Stalk The Turtle Program

So, you decided to play Big Brother with drones and now you want to watch an unsuspecting turtle? Great! This README will guide you through the setup, so you can start spying on... I mean, *observing* turtles.

## Preliminary Nagging

Before you dive headfirst,ensure the following are installed:
- A C++ Compiler that's not from the stone age.
- CMake, because manually compiling is so 1990.

## Dependencies or How to Make Your Code Do Stuff

This code is standing on the shoulders of the Eigen library. It's the mathematical brain that you don't have to pay royalties to.

### Installing Eigen (The Easy Way)

Eigen is a header-only library, which is nerd-speak for "you don't have to compile it." Just make sure it's lurking somewhere in your include path.

For Ubuntu (for those who love typing commands):
```bash
sudo apt-get install libeigen3-dev
```

For macOS (for the 'cool kids' using Homebrew):
```bash
brew install eigen
```

If you're on Windows, good luck. Just kidding, download it from their site or use vcpkg if you fancy that.

## Building the Beast

We've provided a script because we know you'd rather not deal with the hassle of actually writing build commands.

### Run the Magic Script

Crack open a terminal (or command prompt, I don't judge), cd to your project's root like it's your only friend, and type:

```bash
chmod +x build.sh
./build.sh
```

This will unleash the power of CMake and make all the binaries align in harmony.

## Unleashing the Kraken

After building do this

```bash
cd build
./HuntTheTurtle
```

Watch in awe as numbers and possibly correct XYZ coordinates of your turtle flash before your eyes.

