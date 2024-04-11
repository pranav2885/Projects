// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

/*const firebaseConfig = {
  apiKey: "AIzaSyBoczvUy9DRECAVyg-X4HnLONupxShu2RI",
  authDomain: "social-media-f8c72.firebaseapp.com",
  projectId: "social-media-f8c72",
  storageBucket: "social-media-f8c72.appspot.com",
  messagingSenderId: "232059090470",
  appId: "1:232059090470:web:7b67100b428c46a43558e7",
  measurementId: "G-K9M29J4NZ1"
};*/

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);

const firebaseConfig = {
    apiKey: "AIzaSyBoczvUy9DRECAVyg-X4HnLONupxShu2RI",
    authDomain: "social-media-f8c72.firebaseapp.com",
    projectId: "social-media-f8c72",
    storageBucket: "social-media-f8c72.appspot.com",
    messagingSenderId: "232059090470",
    appId: "1:232059090470:web:7b67100b428c46a43558e7",
    measurementId: "G-K9M29J4NZ1"
  };
  
    // Initialize Firebase
  firebase.initializeApp(firebaseConfig);