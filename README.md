# RUSH - ft_contrast

ft_contrast is one of the rushes at 42 that takes an image file path, an output file path and a contrast level percentage to add that amount of contrast level to the image. My partner on this project was [Queenie Ho][1]

This is a 48 hours group project ([I wish...][2]) that taught us multi threaded programming in the C programming language.

**NOTE:** We failed to finish this project in time. At the time of writing, this project is still in progress.

## Project Instructions

[Click here to read the PDF of the project][3] (WARNING: Not for the grammar nazi ¯\\\_(ツ)_/¯)

In summary we must create three commands:
  1. **ft_contrast:** Uses a linear method of reading, calculating and writing for a file.
  2. **ft_contrast_th:** Uses multi threading to do the same thing.
  3. **ft_contrast_tp:** Uses my own thread pool library to make the process even more efficient. Basically just doing *ft_contrast_th* the right way.


## Building and running the project

After cloning or downloading the project, `cd` into the project root directory and run `make`.

For *ft_contrast* only, run: `make ft_contrast`

For *ft_contrast_th* only, run: `make ft_contrast_th`

There might be some errors for *ft_contrast_th*.

To run/test the commands you use the following commands for ft_contrast and ft_contrast_th respectively:

    ./ft_contrast -f feep2.pgm -o result.pgm -c 23

    ./ft_contrast_th -f feep2.pgm -o result.pgm -c 23

They take the following flags followed by their values as arguments:
* **-f**: input file
* **-o:** output file
* **-c:** Contrast level percentage

## Challenges we ran into
- **Time:** We were supposed to have 48 hours, unfortunately we had a 24 hours hackaton the day before. So we ended up just having less than 24 hours.
- **Fatigue**: After that hackathon we were exhausted.
- **Knowledge:** We had to learn multi threaded programming in less than 24 hours... if you've done it in C before you probably know how challenging that would be.

## Conclusion
This was an all-around good project for which I wish we had more time to work on. My team mate was brilliant and we managed to work in harmony during the whole process.

We completed a good deal of it though. This is why we both decided to keep working on it individually and finish it. I for sure will need the skills acquired from it to do my next project in the System branch (minishell) of my school.

Some would say that this is not a good introduction to multi threaded programming. The reason is, at 42 this kind of project is called a Rush, a series of projects that teach you something very specific in programming. Those are not normal introductory projects. Normally we don't have time constraints on projects. This is why they are called Rushes.

## Sponsors

<a href="https://app.codesponsor.io/link/Fo4iMpT8bBWXwb54Lj7DPwqL/R4meau/ft_contrast" rel="nofollow"><img src="https://app.codesponsor.io/embed/Fo4iMpT8bBWXwb54Lj7DPwqL/R4meau/ft_contrast.svg" style="width: 888px; height: 68px;" alt="Sponsor" /></a>

[1]: https://github.com/queenieho
[2]: https://github.com/r4meau/ft_contrast#challenges-we-ran-into
[3]: https://github.com/R4meau/ft_contrast/blob/master/ft_contrast.pdf
