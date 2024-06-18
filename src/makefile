LIBS = -lraylib 
 
windows:
	g++ -o DPets core/renderer/renderEngine.cpp main.cpp $(LIBS) -lgdi32 -lwinmm

windowsR:
	g++ -O2 -o DPets core/renderer/renderEngine.cpp main.cpp $(LIBS) -lgdi32 -lwinmm

% : %.cpp
	g++ -o $@ core/renderer/renderEngine.cpp $< $(LIBS)

linuxR:
	g++ -O2 -o DPets core/renderer/renderEngine.cpp main.cpp $(LIBS)

clean:
	@echo "Deleting..."
	@rm main
