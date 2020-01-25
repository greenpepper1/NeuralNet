CFLAGS = -c -Wall -Iinclude 

units_neuron: neuron_units.c neuron.c
	 gcc -o units_neuron neuron_units.c neuron.c

clean:
	 rm neuron
