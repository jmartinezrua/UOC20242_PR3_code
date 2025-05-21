#ifndef __SUBSCRIPTION_H__
#define __SUBSCRIPTION_H__
#include "csv.h"
#include "date.h"
#include "error.h"
#include "person.h"
#include "watchstack.h"

#define MAX_DOCUMENT 9
#define MAX_PLAN 250

#define NUM_FIELDS_SUBSCRIPTION 7

typedef struct _tSubscription {
    int id;
    char document[MAX_DOCUMENT + 1];
    tDate start_date;
    tDate end_date;
    char plan[MAX_PLAN + 1];
    float price;
    int numDevices;
    tFilmstack watchlist;
} tSubscription;

typedef struct _tSubscriptions {
    tSubscription *elems;
    int count;
} tSubscriptions;

//////////////////////////////////
// Available methods
//////////////////////////////////

// Parse input from CSVEntry
void subscription_parse(tSubscription* data, tCSVEntry entry);

// Copy the data from the source to destination (individual data)
void subscription_cpy(tSubscription* destination, tSubscription source);

// Get subscription data using a string
void subscription_get(tSubscription data, char* buffer);

// Compare two subscription
bool subscription_equal(tSubscription subscription1, tSubscription subscription2);

// Initialize subscriptions data
tApiError subscriptions_init(tSubscriptions* data);

// Return the number of subscriptions
int subscriptions_len(tSubscriptions data);

// Add a new subscription
tApiError subscriptions_add(tSubscriptions* data, tPeople people, tSubscription subscription);

// Remove a subscription
tApiError subscriptions_del(tSubscriptions* data, int id);

// Get subscription data of position index using a string
void subscriptions_get(tSubscriptions data, int index, char* buffer);

// Returns the position of a subscription looking for id's subscription. -1 if it does not exist
int subscriptions_find(tSubscriptions data, int id);

// Print subscriptions data
void subscriptions_print(tSubscriptions data);

// Remove all elements
tApiError subscriptions_free(tSubscriptions* data);

// Calculate Vip Level of a person
int calculate_vipLevel(tSubscriptions* data, char* document);

// Update the vipLevel of each person 
tApiError update_vipLevel(tSubscriptions *data, tPeople* people);

// Return a pointer to the longest film of the list
char* popularFilm_find(tSubscriptions data);

// Return a pointer to the subscriptions of the client with the specified document
tSubscriptions* subscriptions_findByDocument(tSubscriptions data, char* document);

// return a pointer to the subscription with the specified id
tSubscription* subscriptions_findHash(tSubscriptions data, int id);

////////////////////////////////////////////

#endif
