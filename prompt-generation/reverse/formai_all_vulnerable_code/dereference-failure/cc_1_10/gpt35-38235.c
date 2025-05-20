//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Point {
  int x, y;
} Point;

typedef struct Segment {
  Point p1, p2;
} Segment;

typedef struct Event {
  Point point;
  Segment *seg;
  int type;
} Event;

typedef struct Node {
  Segment *seg;
  struct Node *prev, *next;
} Node;

Node *ListInsert(Node *list, Segment *seg) {
  Node *n = (Node*)malloc(sizeof(Node));
  n->seg = seg;
  
  if (!list) {
    n->prev = NULL;
    n->next = NULL;
  } else {
    list->prev = n;
    n->next = list;
    n->prev = NULL;
  }
  
  return n;
}

Node *ListDelete(Node *list, Node *n) {
  if (n->prev)
    n->prev->next = n->next;
  else
    list = n->next;
    
  if (n->next)
    n->next->prev = n->prev;
  
  free(n);
  
  return list;
}

int CompareEvents(const void * a, const void * b) {
  Event *ea = (Event*)a;
  Event *eb = (Event*)b;
  
  if (ea->point.y != eb->point.y)
    return ea->point.y - eb->point.y;
    
  return ea->type - eb->type;
}

int LeftOfSegment(Segment *s, Point *p) {
  float cross = (s->p2.x - s->p1.x) * (p->y - s->p1.y) - (s->p2.y - s->p1.y) * (p->x - s->p1.x);
  
  if (cross > 0)
    return 1;
  
  return 0;
}

Point GetIntersection(Segment *s1, Segment *s2) {
  Point p, a = s1->p1, b = s1->p2, c = s2->p1, d = s2->p2;
  
  float denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);
  
  if (denom == 0)
    return (Point){ .x = -1, .y = -1 };
  
  p.x = ((a.x*b.y - a.y*b.x)*(d.x - c.x) - (a.x - b.x)*(c.x*d.y - c.y*d.x)) / denom;
  p.y = ((a.x*b.y - a.y*b.x)*(d.y - c.y) - (a.y - b.y)*(c.x*d.y - c.y*d.x)) / denom;
  
  return p;
}

void BentleyOttmann(Segment *segments, int n) {
  Event *events = (Event*)malloc(sizeof(Event) * n*2);
  Node *list = NULL;
  int nevents = 0;

  for (int i=0; i<n; i++) {
    if (segments[i].p1.y == segments[i].p2.y)
      continue;
    
    if (segments[i].p1.y > segments[i].p2.y) {
      Point temp = segments[i].p1;
      segments[i].p1 = segments[i].p2;
      segments[i].p2 = temp;
    }
    
    Event e1 = { .point = segments[i].p1, .seg = &segments[i], .type = 1 };
    events[nevents++] = e1;
    Event e2 = { .point = segments[i].p2, .seg = &segments[i], .type = 2 };
    events[nevents++] = e2;
  }

  qsort(events, nevents, sizeof(Event), CompareEvents);
  
  for (int i=0; i<nevents; i++) {
    Event e = events[i];
    
    if (e.type == 1) {
      for (Node *n=list; n; n=n->next) {
        if (n->seg->p1.y < e.point.y && n->seg->p2.y > e.point.y && 
          LeftOfSegment(n->seg, &e.point))
        {
          Point p = GetIntersection(e.seg, n->seg);
          
          printf("Intersection: (%d, %d)\n", p.x, p.y);
        }
      }
      
      list = ListInsert(list, e.seg);
    } else {
      list = ListDelete(list, ListInsert(NULL, e.seg));
    }
  }
}

int main() {
  Segment segments[] = {
    { .p1 = { 2, 1 }, .p2 = { 2, 5 } },
    { .p1 = { 1, 3 }, .p2 = { 5, 3 } },
    { .p1 = { 3, 2 }, .p2 = { 7, 9 } },
    { .p1 = { 0, 2 }, .p2 = { 4, -4 } }
  };
  
  BentleyOttmann(segments, 4);
  
  return 0;
}