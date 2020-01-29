CFLAGS = -c -Wall -Iinclude 

units_neural_net: neural_net_units.c neural_net.c layer.c neuron.c
	 gcc -o units_neural_net neural_net_units.c neural_net.c layer.c neuron.c

units_layer: layer_units.c layer.c neuron.c
	 gcc -o units_layer layer_units.c layer.c neuron.c

units_neuron: neuron_units.c neuron.c
	 gcc -o units_neuron neuron_units.c neuron.c

clean:
	 rm units_neuron
	 rm units_layer
	 rm units_neural_net
