//
//  MessagesViewController.swift
//  MessagesExtension
//
//  Created by Mark Wang on 7/10/17.
//  Copyright © 2017 Nathan and Mark. All rights reserved.
//
import Foundation
import UIKit
import Messages

class MessagesViewController: MSMessagesAppViewController {
    
    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var datetime: UIDatePicker!
    @IBOutlet weak var createButton: UIButton!
    @IBOutlet weak var locationTextField: UITextField!
    @IBOutlet weak var contentView: UIView!
    @IBOutlet weak var ScrollView: UIScrollView!
    
    @IBOutlet weak var emojiTextField: EmojiTextField!

    var scrollViewInsets = UIEdgeInsets.zero
    override func viewDidLoad() {
        
        super.viewDidLoad()

    }
    func layoutCreateController() {
        Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false){_ in
            self.requestPresentationStyle(.expanded)
            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false) {_ in
                self.ScrollView.setContentOffset(CGPoint(x: 0, y: 90), animated: false)
                self.ScrollView.setContentOffset(CGPoint(x: 0, y: -100), animated: false)
            }
        }
        nameTextField.returnKeyType = .next
        locationTextField.returnKeyType = .next
        emojiTextField.returnKeyType = .done
        let tap = UITapGestureRecognizer(target: self, action: #selector(dismissKeyboard))
        view.addGestureRecognizer(tap)
        self.nameTextField.delegate = self
        self.locationTextField.delegate = self
        self.emojiTextField.delegate = self
    }
    func layoutEventPageController(message: MSMessage){
        let storyboard = UIStoryboard(name: "MainInterface", bundle: .main)
        let eventPage = storyboard.instantiateViewController(withIdentifier: "eventPage") as? EventPageViewController
        eventPage?.event = Event(message: message)
        present(eventPage!, animated: false, completion: nil)
    }
    func layoutMapPicker() {
        let storyBoard = UIStoryboard(name: "MainInterface", bundle: .main)
        let locationPicker = storyBoard.instantiateViewController(withIdentifier: "locationViewController") as!LocationViewController
        locationPicker.completion = {location in
            let adress = location?.address
            self.locationTextField.text = adress
            self.locationTextField.becomeFirstResponder()
        }
        present(locationPicker, animated: true, completion: nil)
    }
    override func viewDidLayoutSubviews() {
        let scrollViewBound = ScrollView.bounds
        //let contentViewBound = contentView.bounds
        scrollViewInsets.top = scrollViewBound.size.height/2
        scrollViewInsets.bottom = scrollViewInsets.top
        scrollViewInsets.bottom += 1
        ScrollView.contentInset = scrollViewInsets
    }
    func dismissKeyboard() {
        self.view.endEditing(true)
    }
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        if textField.tag == 4 {
            emojiTextField.becomeFirstResponder()
        } else {
            dismissKeyboard()
        }
        return false
    }
    @IBAction func didTapCreateButton(_ sender: UIButton) {
        
        let name = nameTextField.text
        let datePickerValue = datetime.date
        let location = locationTextField.text
        let emoji = emojiTextField.text
        
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "E, MMM d"
        let date = dateFormatter.string(from: datePickerValue)

        let timeFormatter = DateFormatter()
        timeFormatter.dateFormat = "h:mm a"
        let time = timeFormatter.string(from: datePickerValue)
        
        let event = Event(name: name!, date: date, time: time, location: location!, emojiString: emoji!)
        
        
        let layout = MSMessageTemplateLayout()
        layout.image = event.image
        layout.imageTitle = event.name
        layout.caption = event.date
        layout.subcaption = event.time
        layout.imageSubtitle = event.location
        
        
        //print(dateFormatter.string(from: event.time!))

        //layout.trailingCaption = event.time?.description
        //layout.trailingCaption = String(describing: event.time?.description!)
        
        
        let conversation = activeConversation
        let session = conversation?.selectedMessage?.session ?? MSSession()
//        let totalString = String(emoji!+event.name+event.location+event.time)
//        
//        let url: URL = URL(string:"\(event.name)")!
        var components = URLComponents()
        let nameQuery = URLQueryItem(name: "name", value: event.name)
        let locationQuery = URLQueryItem(name: "location", value: event.location)
        let timeQuery = URLQueryItem(name: "time", value: event.time)
        let dateQuery = URLQueryItem(name: "date", value: event.date)
        let emojiQuery = URLQueryItem(name: "emoji", value: emoji)
        
        components.queryItems = [nameQuery, locationQuery, timeQuery, dateQuery, emojiQuery]
        
        
        let message = MSMessage(session: session)
        message.layout = layout
        message.url = components.url
        
        
        conversation?.insert(message, completionHandler: nil)
        self.requestPresentationStyle(.compact)
    }
    override func didSelect(_ message: MSMessage, conversation: MSConversation) {
        if let url = message.url {
            layoutEventPageController(message: message)
        }
    }

//    override func viewDidAppear(_ animated: Bool) {
//        super.viewDidAppear(animated)
//        Timer.scheduledTimer(withTimeInterval: 0.1, repeats: false) { _ in
//            self.requestPresentationStyle(.expanded)
//        }
//        
//    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Conversation Handling
    
    override func willBecomeActive(with conversation: MSConversation) {
        // Called when the extension is about to move from the inactive to active state.
        // This will happen when the extension is about to present UI.
        if let message = conversation.selectedMessage {
            layoutEventPageController(message: message)
        } else {
            layoutCreateController()
        }
       
        // Use this method to configure the extension and restore previously stored state.
    }
    
    override func didResignActive(with conversation: MSConversation) {
        // Called when the extension is about to move from the active to inactive state.
        // This will happen when the user dissmises the extension, changes to a different
        // conversation or quits Messages.
        
        // Use this method to release shared resources, save user data, invalidate timers,
        // and store enough state information to restore your extension to its current state
        // in case it is terminated later.
    }
   
    override func didReceive(_ message: MSMessage, conversation: MSConversation) {
        // Called when a message arrives that was generated by another instance of this
        // extension on a remote device.
        
        // Use this method to trigger UI updates in response to the message.
    }
    
    override func didStartSending(_ message: MSMessage, conversation: MSConversation) {
        // Called when the user taps the send button.
    }
    
    override func didCancelSending(_ message: MSMessage, conversation: MSConversation) {
        // Called when the user deletes the message without sending it.
    
        // Use this to clean up state related to the deleted message.
    }
    
    override func willTransition(to presentationStyle: MSMessagesAppPresentationStyle) {
        // Called before the extension transitions to a new presentation style.
    
        // Use this method to prepare for the change in presentation style.
    }
    
    override func didTransition(to presentationStyle: MSMessagesAppPresentationStyle) {
        // Called after the extension transitions to a new presentation style.
        if presentationStyle == .expanded {
            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false){_ in 
                self.ScrollView.isScrollEnabled = false
            }
        }
    }
        // Use this method to finalize any behaviors associated with the change in presentation style.
}


extension MessagesViewController: UITextFieldDelegate {
    func textFieldDidBeginEditing(_ textField: UITextField) {
//        if textField.tag == 4 {
//            ScrollView.isScrollEnabled = true
//            ScrollView.setContentOffset(CGPoint(x: 0, y: 90), animated: true)
//            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false){_ in 
//                 self.ScrollView.isScrollEnabled = false
//            }
//           
//        }
        ScrollView.isScrollEnabled = true
        switch textField.tag {
        case 4:
//            ScrollView.setContentOffset(CGPoint(x: 0, y: 90), animated: true)
//            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false){_ in
//                self.ScrollView.isScrollEnabled = false
            layoutMapPicker()
        case 3:
            ScrollView.setContentOffset(CGPoint(x: 0, y: 130), animated: true)
            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false){_ in
                self.ScrollView.isScrollEnabled = false
            }
        default:
            self.ScrollView.isScrollEnabled = false
        }
    }
    func textFieldDidEndEditing(_ textField: UITextField, reason: UITextFieldDidEndEditingReason) {
        if textField.tag == 4 || textField.tag == 3 {
            ScrollView.isScrollEnabled = true
            ScrollView.setContentOffset(CGPoint(x: 0, y: -100), animated: true)
            Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false) {_ in 
                self.ScrollView.isScrollEnabled = false
            }
        }
    }
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
//        if string == "" {
//            return true
//        }
//        if textField.tag == 3 && (textField.text?.characters.count)! >= 1 {
//            return false
//        } else if textField.tag == 3 && string.characters.count <= 2{
//            return true
//        }
        if textField.tag == 3 && string.characters.count <= 3{
            textField.text = string
            return false
        }
        return true
    }
}
