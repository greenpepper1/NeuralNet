CFLAGS = -c -Wall -Iinclude 

units_neuron: neuron_units.c neuron.c
	 gcc -o units_neuron neuron_units.c neuron.c

units_layer: layer_units.c layer.c neuron.c
	 gcc -o units_layer layer_units.c layer.c neuron.c

clean:
	 rm neuron
