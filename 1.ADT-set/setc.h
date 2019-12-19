// ======================================================================

#define TRUE    1
#define FALSE   0

// ======================================================================

typedef struct set {
	int OneSet[1024];
	int count;
} SET;

// ======================================================================

SET *create(void);
int member(SET * set, int element);
int length(SET * set);
SET *insert(SET * set, int element);
SET *_delete(SET * set, int element);
SET *sunion(SET * set1, SET * set2);
SET *intersection(SET * set1, SET * set2);
SET *difference(SET * set1, SET * set2);
void print(SET * set);

// ======================================================================
