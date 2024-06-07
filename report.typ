#import "@preview/plotst:0.2.0": *

#let mkplot(title, file, xlab, ylab, xstep, ystep) = {
	// read csv
	let dat = (
		csv(file)
		.slice(1)                    // remove header
		.map(row => row.map(float))  // convert to float
	)

	// calculate range for graph
	let dat_xmin = calc.min(..dat.map(row => row.at(0)))
	let dat_xmax = calc.max(..dat.map(row => row.at(0)))
	let dat_ymin = calc.min(..dat.map(row => row.at(1)))
	let dat_ymax = calc.max(..dat.map(row => row.at(1)))

	let x_axis = axis(
		min: dat_xmin,
		max: dat_xmax,
		step: xstep,
		location: "bottom",
		helper_lines: false,
		invert_markings: false,
		title: xlab
	)

	let y_axis = axis(
		min: dat_ymin,
		max: dat_ymax,
		step: ystep,
		location: "left",
		helper_lines: false,
		invert_markings: false,
		title: ylab
	)

	// Combine the axes and the data and feed it to the plot render function.
	let pl = plot(data: dat, axes: (x_axis, y_axis))
	scatter_plot(pl, (100%, 20%), caption: title)
}

= Bonus Assignment 1
Wiktor Tomanek [5625173] and  Nikita Soshnin [5571030]

== Using the program

The source code and instructions for compiling and using
are available on github:

- #link("https://github.com/maybeetree/stopandwait")

== Experiment 1

#mkplot(
	"Message length vs number of iterations.",
	"dat/e1.csv",
	"Message Length S",
	"Iterations",
	50,
	100
)

The number of iterations needed to transmit the message
under perfect conditions
(no packet gets corrupted ever)
grows linearly with the length of the message.
This is to be expected.

== Experiment 2

#mkplot(
	"p1 vs number of iterations",
	"dat/e2.csv",
	"Probability of data corruption p1",
	"Iterations",
	0.25,
	2000,
)

We decided to vary $p_1$ in increments of 0.01
because it is a value that is small enough to give a good
representation of the function,
without taking too long to run the experiment.

As the probability of error approaches one,
the number of iterations approaches infinity.
This makes sense, because if a data packet
is guaranteed to be corrupted,
the data will never be sent across.
But for low error probabilities,
this protocol performs relatively well.

== Experiment 3

#mkplot(
	"p2 vs number of iterations",
	"dat/e3.csv",
	"Probability of ACK corruption p2",
	"Iterations",
	0.25,
	2000
)

We decided to vary $p_2$ in increments of 0.01
because it is a value that is small enough to give a good
representation of the function,
without taking too long to run the experiment.

this graph looks very similar to the previous one.
The way the protocol works,
the sender will not stop sending until it has received an ACK
for every item in the message.
So, similar to the previous graph,
there is an asymptote at $p_2 = 1$:
the data will never make it across if the ACKs are guaranteed to fail.
More accurately, it is still possible for the data to be transmitted
correctly, but the sender will never know whether the receiver
has received everything.

