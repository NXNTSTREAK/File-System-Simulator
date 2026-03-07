# NXNT – My Tiny Fake Filesystem (Because Real Ones Hurt My Feelings)

I hit rock bottom somewhere between the 127th "invert binary tree" problem and yet another "serialize this BST while crying" question.

So I did the only reasonable thing left:  
I built a pretend filesystem using trees so I could finally feel like the recursion was worth something.

Welcome to **NXNT**  
(Nothing eXists, Nothing Touches disk)

- 100% in-memory  
- 100% disappears when you rage-quit  
- 0% useful in real life  
- 99% chance of mild entertainment

You get a very serious™ prompt:

```
nxnt:root/$
```

### Available commands (surprisingly not all broken)

```
mkdir banana
mkdir -p existential/crisis/2026
touch please-save-me.txt
rm oops.txt
rm -r whole-career   # yes this works. yes I'm sorry.
cd ..
cd /
cd back-to-reality
ls
tree                # the only pretty thing you'll see today
pwd
mv depression.md coping.md
where my-will-to-live
echo "it's fine"    # it's not fine
history             # forensic evidence of your decline
clear               # desperately tries to wipe the shame
whoami              # nxnt (because even root gave up)
help                # you're beyond help
exit                # sweet release
```

### Live demonstration of me slowly losing the plot

```
nxnt:root/$ mkdir code dreams side-quest
nxnt:root/$ touch todo.txt existential-dread.md
nxnt:root/$ ls
code/  dreams/  existential-dread.md  side-quest/  todo.txt

nxnt:root/$ cd code
nxnt:root/code/$ touch main.cpp    # peak comedy
nxnt:root/code/$ cd ..
nxnt:root/$ rm -r dreams
nxnt:root/$ tree

root
├── code
│   └── main.cpp
├── side-quest
└── todo.txt

nxnt:root/$ where main
root/code/main.cpp

nxnt:root/$ echo "this project will fix me" > todo.txt
nxnt:root/$ rm todo.txt
nxnt:root/$ echo "we moved on (skill issue)"
```

### How to summon the beast

```bash
g++ main.cpp -o nxnt
./nxnt
```

No CMake.  
No dependencies.  
No dignity.

### What actual skills I accidentally levelled up

- Path parsing (the part where I wanted to die)  
- Recursion without stack overflow (mostly)  
- Parent pointers (daddy issues: the data structure)  
- Keeping children sorted alphabetically (OCD simulator 2026 edition)  
- Not leaking memory like it's 2007  
- String splitting without therapy

Still better life choice than 500 more medium tree problems.

### Known issues / features I refuse to fix

- No file contents → no cat, no joy  
- `echo` is dumber than a bag of hammers  
- `mv` only works in current dir (full paths? in this economy?)  
- `rm -rf /` deletes everything — left it in for the vibes  
- No tab completion (I would rather kms)  
- Crashes sometimes → that's a feature called "surprise debugging"

### Roadmap (aka lies I tell myself)

- Add `cat` so I can at least read my own suffering  
- `cp` (why though)  
- Save/load to disk (so the trauma persists)  
- Tab completion (send help)  
- In-memory vim that only knows `:q!` and `:q`

Until then: enjoy your tiny simulated existential crisis.

Feel free to  
• break it  
• fix my memory leaks  
• add the most cursed feature imaginable  
• send screenshots when it segfaults at 3 a.m.

I'm going to stare at valgrind output and question every life choice that led me here.

Catch you in the next burnout project. 😭